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
  node* head;
  node* rear;


void menuScreen();      // 메뉴화면 출력하는 함수
int menuSelect();       // 메뉴 선택 입력하는 함수


int main()
{


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

void initQue()      // 큐 초기화 함수
{
    head = (node*)malloc(sizeof(node));         // 동적 메모리 할당
    rear = (node*)malloc(sizeof(node));

    // 초화화 상태 연결
    head->pre = head;
    head->next = rear;
    rear->pre = head;
    rear->next = rear;
}



int isEmpty()       //덱이 공백인지 아닌지 검사
{
    if (NULL) {

        printf("\n Linked Queue is empty! \n");

        return 1; //front 널이면 종료

    }
    else return 0;
}
