/* 이 프로그램은 이중 연결리스트를 이용하여 큐를 구현한 프로그램입니다.
삽입, 탐색, 삭제가 가능하며, 기능에 해당하는 메뉴를
선택하여 사용합니다.
2015244020_장우진 */

#include <stdio.h>
#include <stdlib.h>


typedef struct pcb      // PCB 구조체 선언부
{
    int pid;
    char state;
    int priority;
    char memLocation;
    int scheduleInfo;
    struct pcb* pre;
    struct pcb* next;
} node;

typedef struct Queue
{
    int count;
    node* head;
    node* rear;
} queue;


void menuScreen();      // 메뉴화면 출력하는 함수
int menuSelect();       // 메뉴 선택 입력하는 함수
void initQue(queue* que);      // 큐 초기화 함수
int isEmpty(queue* que);     //큐가 공백인지 아닌지 검사
void inputData(queue* que);            // PCB 정보 입력 함수
void enQueue(queue* que, int pid, char state, int priority, char memLoc, int schedule);

int main()
{
    queue que;


    while (1) {

        menuScreen();


        switch (menuSelect())
        {
        case 1:

            system("puase");
            system("cls");
            system("cls");
            break;
        case 3:

            system("puase");
            system("cls");
            break;
        case 4:

            system("puase");
            system("cls");
            break;
        case 5:

            system("puase");
            system("cls");
            break;
        case 6:
            break;
        case 2:

            system("puase");

            exit(0);
            break;
        }
    }
    return 0;
}

void menuScreen()       // 메뉴화면 출력 함수
{
    printf("┏━━━━━━━━  메뉴 ━━━━━━━━━━┓\n");
    printf("┃     1. 삽입하기         ┃\n");
    printf("┃     2. 출력하기         ┃\n");
    printf("┃     3. 탐색하기         ┃\n");
    printf("┃     4. 삭제하기         ┃\n");
    printf("┃     5. 종료하기         ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    printf("\n\n");
}

int menuSelect()        // 메뉴 선택 입력 함수
{
    int menuNum;

    printf("메뉴 선택 : ");
    scanf_s("%d", &menuNum);

    return menuNum;
}

void initQue(queue *que)      // 큐 초기화 함수
{
    que->head = NULL;
    que->rear = NULL;
    que->count = 0;
}

int isEmpty(queue *que)       //큐가 공백인지 아닌지 검사
{
    if (que-> count == 0) {

        printf("\n Linked Queue is empty! \n");

        return 1;

    }
    else return 0;
}

void inputData(queue* que)      // PCB 정보 입력 함수
{
    int inputPID;
    char state;
    int priority;
    char memLocation;
    int scheduleInfo;

    printf("\n\n");
    printf("PID 설정 >> "); scanf_s("%d", &inputPID);
    printf("우선순위 설정 >> "); scanf_s("%d", &priority);
    printf("메모리 위치 설정 >> "); scanf_s("%s", &memLocation);
    printf("스케쥴정보 설정 >> "); scanf_s("%d", &scheduleInfo);

    enQueue(que, inputPID,'r', priority, memLocation, scheduleInfo);
}

void enQueue(queue* que, int pid, char state, int priority, char memLoc, int schedule)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->pid = pid;
    tmp->state = state;
    tmp->priority = priority;
    tmp->memLocation = memLoc;
    tmp->scheduleInfo = schedule;
    tmp->next = NULL;

    if (isEmpty(que))       // 큐가 비어있을 때
    {
        que->head = tmp;
    }
    else                    // 큐가 비어있지 않을 때
    {
        que->rear->next = tmp;
    }
    que->rear = tmp;        // 맨 뒤를 tmp로 인식
    que->count++;           // 보관 개수 증가
}

void deQueue()          // 큐 삭제 함수
{

}

void printQueue()       // 큐 전체 출력 함수
{

}

node* searchPCB()       // 큐 검색 함수
{

}

void deleteSelectedPCB()
{

}
