#include <stdio.h>
#include <stdlib.h>
#define MAX 30


// This function can decode as Well as Encode 
char *encode (char *, int);




int main(void){
   // Str takes the String
   //num takes the number of shift.
   char str[MAX]; int num;
   fgets(str,MAX,stdin);
   printf("Shift: ");
   do{scanf("%d",&num);}while(getchar() != '\n');
   printf("%s",encode(str,x));

   return 0;
}


char *encode (char *str, int shift){
   char * c;
   int diff;

    while(shift >= 26 || shift <= -26){ // 1-26 is a  1 alphabet cycle so this function converts the given shift in sift within in 26 
         if(shift >= 26){
            shift = shift -26; 
         }else{
            shift = shift +26; 
         }
      }

   for (c = str; *c != '\0'; ++c)
   {
      if((*c >= 'A' && *c <= 'Z' ) || (*c >= 'a' && *c <= 'z' ) )
      {
            diff = *c + shift;

         if( *c >= 'a')
         {

            if(diff < 'a' ){
                  *c = 'z' -(97- (diff+1));
            }else if( diff > 122){
               *c = 'a' +((diff-1) -122);
            }else{
               *c = diff;
            }

         }else
         {

            if(diff <'A' ){
                  *c = 'Z' -(65- (diff+1)) ;
             }else if( diff > 90){
               *c = 65 +((diff-1) -90);  
            }else{
               *c = diff;
               
            }
         }
      }
      
   }
   return str;
}