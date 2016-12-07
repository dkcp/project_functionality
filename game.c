#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define CC SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3)
#define RC SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7)
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void show();
int* move(int* board, char dir);

int board[7][30]={1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,
					  1,3,1,2,2,2,2,0,0,0, 1,1,1,1,0,1,0,0,0,0, 0,1,2,2,1,2,2,0,0,1,
					  1,0,1,2,2,2,2,0,0,0, 0,0,0,1,0,0,0,1,0,0, 0,1,2,2,2,2,1,0,0,1,
					  1,0,1,2,2,2,2,1,0,0, 1,0,0,1,1,1,1,1,0,1, 0,0,1,2,2,1,0,0,0,1,
					  1,0,1,1,1,1,1,1,0,0, 1,0,0,0,0,0,0,1,0,1, 0,0,0,1,1,0,0,1,0,1,
					  1,0,0,0,0,0,0,0,0,0, 1,0,0,1,0,0,0,0,0,1, 1,0,0,0,0,0,0,1,0,1,
					  1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1};
	
void main()
{
	int* player;
	char direction = 0;
	player = &board[1][1];
	
	show();

	while(1){
		direction = getch();
		
		switch(direction){
		case UP:	
			if(*(player-30)==0 || *(player-30)==2){
				*player = 0;
				player = player-30;
				*player = 3;
			}
			break;
		case RIGHT:	
			if(*(player+1)==0 || *(player+1)==2){
				*player = 0;
				player = player+1;
				*player = 3;
			} 
			break;
		case DOWN:	
			if(*(player+30)==0 || *(player+30)==2){
				*player = 0;
				player = player+30;
				*player = 3;
			} 
			break;
		case LEFT:
			if(*(player-1)==0 || *(player-1)==2){
				*player = 0;
				player = player-1;
				*player = 3;
			} 
			break;
		default: break;
		}

		show();
	}

	scanf("%d");
}

void show(){
	int i, j;

	for(i=0 ; i<7 ; i++){
		for(j=0 ; j<30 ; j++){
			switch(board[i][j]){
			case 0 : printf("  "); break;
			case 1 : printf("¡á"); break;
			case 2 : CC; printf(",,"); RC; break;
			case 3 : printf("¿Ê"); break;
			default : break;
			}
		}
		printf("\n");
	}
}