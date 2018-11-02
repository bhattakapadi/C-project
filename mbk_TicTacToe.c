/*
	mbk_Tictactoe
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COlOUM 3
#define  WIN 'W'
#define CONTINUE 'C'

char player1 = 'X';
char player2 = 'O';
char box[ROWS][COlOUM];

void gameBox();  //create the Box and update each step
unsigned char checkWin( char);	//check if someone Wins
char nextPlayer(char );	// change player + check the input


int main()
{
	gameBox();
	char buff= player1, puff;
	int draw= 0, loopCheck= 0;;
	do{	
		puff= buff;
		buff= (buff ==  player1)? nextPlayer(player2): nextPlayer(player1);
		if(buff == 'W'){
			(puff == player1)? (puff= player2):(puff= player1);
			break;
		}
		draw++;
		printf("\n\n\n\n");
	} while(draw != 9);
	if(draw == 9) printf("Match is Draw");
	if(buff == 'W')printf("Winner is %c Player ",puff);

	
	return EXIT_SUCCESS;
}


void gameBox()
{
	printf("%20s"," "); printf("  1      2     3   \n");
	for (int i = 0; i <= 3; ++i)
	{
	
		 printf("%20s"," ");printf("*-----*-----*-----*\n");
		 if( i< 3)
		 {
		 	printf("%19s"," "); printf("%d| ",i+1);  
			for (int j = 0; j < 3; ++j)
			{
				
				if(box[i][j] == 'X'|| box[i][j] == 'O'){
					printf("%2c",box[i][j]);
					printf("  ");	
				} 
				else
				{
					printf("    ");
				}
				printf("| "); 
			}
			printf("\n");
		}
		
	}

}





char nextPlayer(char player10)
{
	printf("\nTurn for \"%c\" Player!\n",player10);
	unsigned int num1,num2, count=0;
	// checking if the Number are Correct or the Number are Already taken.  
	man:
	printf("\nEnter the Row[1-3] :");
	do{scanf("%u",&num1);}while(getchar() != '\n' );
	if(num1 < 1 || num1 >3 ) goto man; 
	printf("\nEnter the coloum[1-3] :");
	do{scanf("%u",&num2);}while(getchar() != '\n' );
	if(num2 <1 || num2 >3 ) goto man; 
	if(box[num1-1][num2-1] == 'X' || box[num1-1][num2-1] == 'O') goto man;	// Checking weather the Place have already data

	box[num1-1][num2-1] = player10;  // Assigning the value to the Array
	printf("\n\n\n");
	gameBox();
	if(checkWin(player10) == WIN) return WIN;
	 
	if(player10 == 'X') return player1;
	if(player10 == 'O') return player2;
}


 unsigned char  checkWin(char player)
{	
	if(box[0][0] == player && box[0][1] == player && box[0][2] == player || 
	   box[1][0] == player && box[1][1] == player && box[1][2] == player || 
	   box[0][0] == player && box[1][0] == player && box[2][0] == player ||
	   box[0][1] == player && box[1][1] == player && box[2][1] == player ||  
	   box[0][2] == player && box[1][2] == player && box[2][2] == player || 
	   box[0][0] == player && box[1][1] == player && box[2][2] == player ||  
	   box[2][0] == player && box[2][1] == player && box[2][2] == player )
	{
		return WIN;
	}

}
