/*
   @mbk
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

char *encode (char *, int); // This function can decode as Well as Encode 

int main(void){
   // Str takes the String
   //num takes the number of shift.
   char str[MAX]; int num;
   printf("\nEnter the String: ");
   fgets(str,MAX,stdin);
   printf("Shift(negative = towards Left  \t positive : towards right ): ");
   do{scanf("%d",&num);}while(getchar() != '\n');
   printf("%s",encode(str,num));
   return 0;
}

char *encode (char *str, int shift){
   char * c;
   int diff;
   shift=shift%26; // 1-26 is a  1 alphabet cycle so this function converts the given shift in sift within in 26     

   for (c = str; *c != '\0'; ++c) {
         diff = *c + shift;
         if(*c >= 'a' && *c <= 'z'){
            if(diff < 'a' ){
                  *c = 'z' -(96- diff);
            }else if( diff > 122){
               *c = 'a' +((diff- 123);
            }else{
               *c = diff;
            }
         }else if (*c >= 'A' && *c <= 'Z'){
            if(diff <'A' ){
                  *c = 'Z' -(64-diff) ;
             }else if( diff > 90){
               *c = 65 +((diff-91);  
            }else{
               *c = diff;
               
            }
         }
      }
   return str;
}
