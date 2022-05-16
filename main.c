#include "srcc.h"
#define SIZE 20
int main(void)
{

    Privacy s[SIZE];
    int count = 0, menu;
    int index = 0;

    count = loadData(s);
    index = count;
    
    for(int i=0; i<SIZE; i++){
        s[i].arrive_time_hour=0;
        s[i].arrive_time_min=0;
        s[i].arrive_time_sec=0;
        s[i].leave_time_hour=0;
        s[i].leave_time_min=0;
        s[i].leave_time_sec=0;
    }
    while (1)
    {
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1)
        {
            readPrivacy(s, index);
        }
        else if (menu == 2)
        {
            if (count <= 20) //특정개수를 초과하면 안됨
            {
                count += addPrivacy(&s[index++]); //특정 배열의 주소를 보내주기 때문에 &을 꼭 써야함!!
            }
            else
            {
                printf("더 이상 추가할 수 없습니다.\n");
            }
        }
        else if (menu == 3)
        {
            int answer = askIndex(s, index);
            if (answer != 0)
            {
                updatePrivacy(&s[answer - 1]); // answer-1을 하는 이유:  index가 0부터 시작하기 때문
            }
            else
            {
                printf("수정할 수 없습니다.\n");
            }
        }
        else if (menu == 4)
        {
            int answer = askIndex(s, index);
            if (answer == 0)
            {
                printf("=> 취소되었습니다.\n");
                continue;
            }
            else
            {
                int delete;
                printf("정말로 삭제하시겠습니까?(삭제 :1)");
                scanf("%d", &delete);
                if (delete == 1)
                {
                    if (deletePrivacy(&s[answer - 1]))
                    {
                        count--;
                        printf("=> 삭제되었습니다.\n");
                    }
                }
            }
        }
        else if (menu == 5) //출퇴근 입력 메뉴
        {
            checkCommute(s, index);
        }
        else if (menu == 6) // 출퇴근 조회
        {
            readCommute(s, index);
        }
        else if (menu == 7) // 파일 저장 메뉴
        {
            saveData(s, index);
        }
        else if (menu == 8) // 검색 메뉴
        {
            findPrivacy(s, index);
        }
        if (menu == 9)//지각자 확인 메뉴
        {
            int num = checkLate(s,index);
            printf("지각자/결석자 %d명\n",num);
            printf("1. 지각자\n");
            printf("\nNo Position Name Age  Phone_num    Speicial_num  Pwd \n");
            printf("====================================================\n");
            for(int i=0; i<index; i++){
                if(s[i].flag==1) read_OneCommute(s[i]);
            }
            printf("2. 결석자\n");
            for(int i=0; i<index; i++){
                if(s[i].flag==2) read_OneCommute(s[i]);
            }
        }

    }

    printf("\n==> 종료되었습니다 <==\n");
    return 0;
}