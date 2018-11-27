/*
   @mbk
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30


// This function can decode as well as encode 
char *encode (char *, int);



int main(void){
   // Str takes the String
   //num takes the number of shift.
   // negative value for left-shift
   //positive value for right-shift
   char str[MAX]; int num;
   printf("\nPlease enter the String: ");
   fgets(str,MAX,stdin);
   printf("Shift: ");
   do{scanf("%d",&num);}while(getchar() != '\n');
   printf("%s",encode(str,num));

   return EXIT_SUCCESS;
}


char *encode (char *str, int shift){
   char * c;
   int diff;
   // 1-26 is a  1 alphabet cycle 
   //so this function converts the given shift > 26  in shift within in shift <= 26 
    while(shift >= 26 || shift <= -26){ 
         if(shift >= 26){
            shift = shift -26; 
         }else{
            shift = shift +26; 
         }
      }

   for (c = str; *c != '\0'; ++c)
   {
      if((*c >= 'A' && *c <= 'Z' ) || (*c >= 'a' && *c <= 'z' ) )// Takes only String 
      {
            diff = *c + shift;   // add or Subtract  with current ascii value of the Character.
         if( *c >= 'a')
         {

            if(diff < 97 ){  //diff < 'a'
                  *c = 122 -(97- (diff+1));  // subraction the negative shift starting from  Z
            }else if( diff > 122){
               *c = 97 +((diff-1) -122);    // add the positive shift stating from  a
            }else{
               *c = diff;         // add the normal shift to the Alphabet 
            }

         }
         else
         {

            if(diff < 65  ){   // diff < ' '
                  *c = 90 -(65- (diff+1)) ;  // subraction the negative shift starting from  z
             }else if( diff > 90){
               *c = 65 +((diff-1) -90);  // add the positive shift stating from  a
            }else{
               *c = diff;    // add the normal shift to the Alphabet 
               
            }
         }
      }
      
   }
   return str;
}
