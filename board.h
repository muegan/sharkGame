#define BOARDSTATUS_OK		1
#define BOARDSTATUS_NOK		0

#define N_BOARD				15

int board_initboard(void); //���� �ʱ�ȭ
int board_printfBoardStatus(void); //������ ���� ���


int board_getBoardStatus(int pos); // Ư�� ĭ�� �ļ� ���� ��� 
int board_getBoardCoin(int pos); // ������ ���� 

//int board_getSharkPosition(void); // ����� ��ġ ���
int board_stepShark(void); // ��� ���� ���
