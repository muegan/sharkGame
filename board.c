#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_COINPOS		12
#define MAX_COIN		4

#define MAX_SHARKSTEP	6
#define SHARK_INITPOS	-4


static int board_status[N_BOARD]; // 보드의 상태 배열 
static int board_coin[N_BOARD]; // 보드 위의 코인 배열

static int board_sharkPosition; // 상어의 위치 

int board_initboard(void)
{
	int i; 
	for(i=0;i<N_BOARD;i++){
		board_status[i] = BOARDSTATUS_OK;
		board_coin[i] = 0;
	}
	
	board_sharkPosition = SHARK_INITPOS;
	
	// coin 할당 
	for(i=0;i<N_COINPOS;i++)
	{	
		int flag = 0;		 
		while (flag == 0)
		{
			int allocPos = rand()%N_BOARD; //0~14 숫자 랜덤
			if (board_coin[allocPos] == 0)
			{
				board_coin[allocPos] = rand()%MAX_COIN+1; //1~4 사이 값 
				flag = 1;
			}
		}
	}
	
	return 0;
}

int board_printBoardStatus(void){
	
	int i;
	printf("----------BOARD STATUS----------\n");
	for(i=0;i<N_BOARD;i++)
	{
		printf("|");
		if (board_status[i]==BOARDSTATUS_NOK)
			printf("X");
		else
			printf("O");
	}
	printf("|\n");
	printf("--------------------------------\n");
	
	return 0;
}


int board_getBoardStatus(int pos){
	return board_status[pos];
}

int board_getBoardCoin(int pos){
	int coin = board_coin[pos];
	board_coin[pos]=0;
	return board_coin[pos];
}

//int board_getSharkPosition(void)
int board_stepShark(void){
	int step = rand()%MAX_SHARKSTEP + 1 ;
	int i;
	for(i=board_sharkPosition+1;i<=board_sharkPosition+step;i++){
	
		if(i>=0 && i<N_BOARD)
			board_status[i] = BOARDSTATUS_NOK;
	}
	
	board_sharkPosition += step;
	
	return board_sharkPosition;
	
}
