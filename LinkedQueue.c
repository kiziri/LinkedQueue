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
    int memLocation;
    int scheduleInfo;
    struct pcb* pre;
    struct pcb* next;
} node;

typedef struct Queue
{
    int count;
    node* front;
    node* rear;
} queue;


void menuScreen();      // 메뉴화면 출력하는 함수
int menuSelect();       // 메뉴 선택 입력하는 함수
void initQue(queue* que);      // 큐 초기화 함수
int isEmpty(queue* que);     //큐가 공백인지 아닌지 검사
void inputData(queue* que);             // PCB 정보 입력 함수
void enQueue(queue* que, int pid, char state, int priority, int memLoc, int schedule);     // PCB 정보 삽입
void deQueue(queue* que);               // 큐 순서 실행상태 삭제 함수
void printQueue(queue* que);            // 큐 전체 출력 함수
node* searchPCB(queue* que, int PID);             // 큐 검색 함수
void printSearch(queue* que);            // 검색한 큐 결과 출력
void deleteSelectedPCB(queue* que);     // 선택한 PCB만을 삭제 함수

int main()
{
    queue que;
    initQue(&que);

    while (1) {

        menuScreen();
        switch (menuSelect())
        {
        case 1:
            inputData(&que);
            system("pause");
            fflush(stdin);
            break;
        case 2:
            printQueue(&que);
            system("pause");
            fflush(stdin);
            break;
        case 3:
            printSearch(&que);
            system("pause");
            fflush(stdin);
            break;
        case 4:
            deleteSelectedPCB(&que);
            system("pause");
            fflush(stdin);
            break;
        case 5:
            deQueue(&que);
            system("pause");
            fflush(stdin);
            break;
        case 6:
            printf("\n\n프로그램을 종료합니다.\n\n");
            exit(0);
            break;
        }
        system("cls");
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
    printf("┃     5. 실행으로 이동    ┃\n");
    printf("┃     6. 종료하기         ┃\n");
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
    que->front = NULL;
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
    char state = 't';
    int priority;
    int memLocation;
    int scheduleInfo;

    printf("\n\n새로운 노드 정보 입력 및 삽입");
    printf("\n\n");
    printf("PID 설정 >> "); scanf_s("%d", &inputPID);
    printf("우선순위 설정 >> "); scanf_s("%d", &priority);
    printf("메모리 위치 설정 >> "); scanf_s("%d", &memLocation);
    printf("스케쥴정보 설정 >> "); scanf_s("%d", &scheduleInfo);

    enQueue(que, inputPID, state, priority, memLocation, scheduleInfo);
}

void enQueue(queue* que, int pid, char state, int priority, int memLoc, int schedule)
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
        que->front = tmp;
    }
    else                    // 큐가 비어있지 않을 때
    {
        que->rear->next = tmp;
    }
    que->rear = tmp;        // 맨 뒤를 tmp로 인식
    que->count++;           // 보관 개수 증가

    printf("\n\n준비 큐에 새로운 노드 추가 완료\n\n");
}

void deQueue(queue *que)          // 큐 순서 실행상태 삭제 함수
{
    node* tmp;

    if (isEmpty(que))       // 큐가 비어있을 때
    {
        return;
    }
    tmp = que->front;           // 제일 앞에 있는 노드를 tmp에 저장
    que->front = tmp->next;     // tmp의 다음 노드를 front로 지정
    free(tmp);                  // 동적 할당 해제로 소멸
    que->count--;               // 보관 개수 감소
    printf("\n\n다음 PCB가 실행 상태에 들어갔습니다.\n\n");
}

void printQueue(queue *que)       // 큐 전체 출력 함수
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp = que->front;
    int cnt = que->count - 1;

    printf("\n\n\nQueue Data List\n");
    printf("Data.NO\tPID\tState\tPriority\tMem.Loc\tSchedule.info\n");

    while (tmp != NULL)
    {
        printf("%d Data >> %d\t%c\t%d\t%c\t%d \n", que->count - (cnt--), tmp->pid, tmp->state,
                                                    tmp->priority, tmp->memLocation, tmp->scheduleInfo);
        tmp = tmp->next;
    }

    printf("\n\n");
}

node *searchPCB(queue* que, int PID)       // 큐 검색 함수
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp = que->front;

    while (tmp != NULL)
    {
        if (PID == tmp->pid);
        {
            return tmp;
        }

        if (isEmpty(que))       // 큐가 비어있을 때
        {
            return 0;
        }
        tmp = tmp->next;
    }

    return 0;
}

void printSearch(queue* que)            // 검색한 큐 결과 출력
{
    int inputPID;
    int cnt = que->count - 1;
    node* tmp;

    printf("\n\n\n검색하고 싶은 PCB : ");
    fflush(stdin);
    scanf_s("%d", &inputPID);
    tmp = searchPCB(que, inputPID);

    if (searchPCB(que, inputPID) == 0)
    {
        printf("\n\n 검새하고자 하는 PCB가 없습니다.\n\n");
        return;
    }

    printf("\n\n검색한 PID의 결과\n");
    printf("Data.NO\tPID\tState\tPriority   Mem.Loc\tSchedule.info\n");
    printf("%d Data >> %d\t%c\t%d\t%c\t%d \n", que->count - (cnt--), tmp->pid, tmp->state,
        tmp->priority, tmp->memLocation, tmp->scheduleInfo);

    printf("\n\n");
}

void deleteSelectedPCB(queue* que)        // 선택한 PCB만을 삭제 함수
{
    int inputPID;
    int cnt = que->count - 1;
    node* tmp, *pre;
    tmp = que->front;
    pre = que->front;

    printf("\n\n\n삭제하고 싶은 PCB : ");
    fflush(stdin);
    scanf_s("%d", &inputPID);

    if (searchPCB(que, inputPID) == 0)
    {
        printf("\n\n 삭제하고자 하는 PCB가 없습니다.\n\n");
        return;
    }

    while (tmp != NULL)
    {
        if (tmp->pid == inputPID)
        {
            if (tmp == que->front && tmp == que->rear)          // 큐에 PCB가 1개 뿐일 때
            {
                que->front = NULL;
                que->rear = NULL;
                que->count = 0;
                free(tmp);
                printf("\n\n해당 PID의 PDB 삭제 완료!\n\n");
                return;
            }

            if (tmp == que->front)          // 큐에 해당 PCB가 가장 앞일 때
            {
                que->front = que->front->next;
                que->count--;
                free(tmp);
                printf("\n\n해당 PID의 PDB 삭제 완료!\n\n");
                return;
            }

            if (tmp == que->rear)          // 큐에 해당 PCB가 가장 마지막일 때
            {
                pre->next = NULL;
                que->count--;
                free(tmp);
                printf("\n\n해당 PID의 PDB 삭제 완료!\n\n");
                que->rear = pre;
                return;
            }
            else                                                // 큐에 해당 PCB가 중간에 있을 때
            {
                pre->next = tmp->next;
                que->count--;
                free(tmp);
                printf("\n\n해당 PID의 PDB 삭제 완료!\n\n");
                return;
            }
        }
        pre = tmp;
        tmp = tmp->next;
    }
}
