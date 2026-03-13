/*
Programming Studio C003
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]);                                                               // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main()
{
    char mnames[10][20];        // 남학생명단(최대 10명)
    int mroom[10];              // 남학생명단별 호실 배정 목록
    char wnames[10][20];        // 여학생명단(최대 10명)
    int wroom[10];              // 여학생명단별 호실 배정 목록
    int person[2][5] = {0};     // 2개 층별 5개 호실의 배정 인원 수
    int mcount = 0, wcount = 0; // 인원 합계 (남, 여)
    int menu;

    srand(time(0));
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");
    while (1)
    {
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &menu);
        if (menu == 0)
            break;
        else if (menu == 1)
        {
            if (mcount >= 10)
            {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]); // person[0] : 1층 (남자층)
            mroom[mcount] = 100 + roomno;     // 10명 중 mocount번째 학생의 호실은 100 + roomno이다.
            printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
            mcount++;
        }
        else if (menu == 2)
        {
            if (wcount >= 10)
            {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]); // person[1] : 2층 (여자층)
            wroom[wcount] = 200 + roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
            wcount++;
        }
    }

    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5])
{
    // 이 곳에 생각 정리와 코드 구현
    /*
    < 생각 정리 >
    함수 findRoom은 5개의 호실 중 빈 베드가 있는 방을 "랜덤으로" 찾아낸다. (리턴값 : 호실번호 (1~5)) -> 2명 모두 배정된 호실을 배정하면 안됨!
    파라미터는 "5개 호실 내에 이미 배정된 사람의 숫자 배열" 이다. (호출한 층에 대한 호의 개수 5개!)
    예를 들어, 101호에 0명이 있다면 persons[0] = 0,
    예를 들어, 101호에 1명이 있다면 persons[0] = 1,

    예를 들어, 102호에 0명이 있다면 persons[1] = 0,
    예를 들어, 102호에 1명이 있다면 persons[1] = 1,

    person[0] = 101호, 201호
    person[1] = 102호, 202호
    person[2] = 103호, 203호
    person[3] = 104호, 204호
    person[4] = 105호, 205호

    findRoom 에서는 빈 베드가 있는 방을 랜덤으로 찾아내야 한다 !! 만약 빈 베드가 있는 방이라면 바로 그 방 roomno를 리턴값으로 뱉기 !
    그럼 "랜덤으로" 접근하는 방법?
    : rand() % 5;
    */

    int random_no = rand() % 5;  // 0 ~ 4 사이의 랜덤 번호
    if (persons[random_no] >= 2) // 랜덤으로 접근한 호의 방이 꽉 찼다면
    {
        return findRoom(persons);
    }

    persons[random_no]++;
    return random_no + 1;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc)
{
    // 이 곳에 생각 정리와 코드 구현
    // 파라미터 : 남학생 이름 배열(mn), 남학생 배정된 호실번호 배열(mr), 등록된 남학생 수(mc),
    //          여학생 이름 배열(wn), 여학생 배정된 호실번호 배열(wr), 등록된 여학생 수(wc)
    // 리턴값 : 없음

    printf("남학생 명단 (%d명)\n", mc);
    for (int i = 0; i < mc; i++)
    {
        printf("%d. %s [%d호]\n", i + 1, mn[i], mr[i]);
    }

    printf("\n");

    printf("여학생 명단 (%d명)\n", wc);
    for (int i = 0; i < wc; i++)
    {
        printf("%d. %s [%d호]\n", i + 1, wn[i], wr[i]);
    }

    printf("\n");

    printf("호실별 배정 명단\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d호 : ", 100 + (i + 1));
        for (int j = 0; j < 10; j++)
        {
            if (mr[j] == 100 + (i + 1))
            {
                printf("%s ", mn[j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d호 : ", 200 + (i + 1));
        for (int j = 0; j < 10; j++)
        {
            if (wr[j] == 200 + (i + 1))
            {
                printf("%s ", wn[j]);
            }
        }
        printf("\n");
    }
}
