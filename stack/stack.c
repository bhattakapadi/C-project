#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*
 *Structure for stack 
 *value store the data 
 * nextPtr points to next element in the Array
*/

typedef struct stackElement {
	int value;
	struct stackElement * nextPtr ;
}stack;





int push(stack **,int);                               // push the Element int the satcks
bool containsElement(stack *,int );                  // for checking is the element is present
stack * allocateMemory(int );                        // allocate memory for the the stack
void printElement(stack *);                          // print the element in the Array
int pop(stack **); 				// delete the element at he top of the Stack





int main(int args, char *argv[]){
	stack *str = NULL;

	printf("Number pushed:  %d\t\n",push(&str,9));
	printf("Number pushed:  %d\t\n",push(&str,8));
	printf("Number pushed:  %d\t\n",push(&str,10));
	printf("Number pushed:  %d\t\n",push(&str,8));
	printf("Number pushed:  %d\t\n",push(&str,12));
	printf("Number pushed:  %d\t\n",push(&str,12));
	printElement(str);


	printf("\n\nElement poped:%d\n",pop(&str));
	printElement(str);


	return EXIT_SUCCESS;
}


/* 
*	@param stk: takes the address of the Stack present in the Main function
	@pararm number: takes the number that is to be pushed in the Stack
	@returns  : if pushed return the Number that is pushed  else gives -1 back
*/

int push(stack ** stk,int number){
	bool pushComplete = false;                 // tells if the push is complete

	if( *stk == NULL){
		*stk = allocateMemory(number);      // if empty makes the head
		pushComplete = true;               
	}else{
		if(!containsElement(*stk,number)){       // checks if the element is already present in the Array 
			stack * tmp = *stk;
			
			 while((tmp)->nextPtr != NULL){      // goes to the Last element in the Array
				tmp = tmp->nextPtr; 
			}
			tmp->nextPtr = allocateMemory(number);
			pushComplete = true;
		}


	}

	return !pushComplete ? -1 : number;
	
}


/*allocate memory for the Next Element!!
 *@nparam umber:  takes the Number that is to be stored
 * @returns : returns the Pointer to the newly created array
 */
stack  * allocateMemory(int number){
	stack * tmp =NULL;
	if((tmp = (stack *)malloc(1*sizeof(1*sizeof(stack)))) != NULL){
			tmp->value = number;
			tmp->nextPtr = NULL;
	}else {
		perror("Unable to Allocate Memory!!\n");
		return NULL;
	}
	return tmp;  // returns the address of the new node 
}


/*
  *@param stk : takes the address fo the head
  *@ returns : gives true if the Element is already present in the Array else returs false
  */

bool containsElement(stack *stk, int number){
	bool found = false;
	if(stk != NULL){
		for (stack * tmp = stk; tmp !=NULL; tmp = tmp->nextPtr){
			if(tmp->value == number){
				found = true;
				break;
			}
		}
		
	}
	return found;
}




/*
 *@param stk : points to the Head
*/

void printElement(stack * stk1){
	if(stk1 == NULL ) printf("Stack is Empty!");
	printf("\nElement in Stack: ");
	stack * stk = stk1;
	while(stk != NULL){
		printf("%d,", stk->value);
		stk= stk->nextPtr;
	}
	printf("NULL \n");
}

/*
*@param stk: access to the Head
*@returns: returns the number that is poped if present else gives -1 back
*/

int pop(stack ** stk){
	int number = -1;
	if(*stk != NULL){
		stack * tmp = *stk;
		stack * tmp2= tmp->nextPtr;	
		while(tmp2->nextPtr != NULL){
			tmp = tmp2;
			tmp2 =tmp2->nextPtr;
		}
		
		number = tmp2->value;
		free(tmp2);
		tmp->nextPtr =NULL;

	}
	return number;
}
