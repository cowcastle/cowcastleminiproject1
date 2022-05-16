#include "srcc.h"

char masterkey[30] = {"1234 abcd!"};

int checkMasterkey()
{
    char temp_mk[30];
    printf("계속하시려면 Masterkey를 입력해주세요 =>\n");
    getchar();
    fgets(temp_mk, 30, stdin);
    temp_mk[strlen(temp_mk) - 1] = '\0';

    int temp = strcmp(masterkey, temp_mk);

    if (temp == 0)
        return 1;
    else
        return 0;
}

int selectMenu()
{
    int menu;
    printf("\n***** 출근 관련 메뉴 *****\n");
    printf("1. 인원 조회 \n");
    printf("2. 인원 추가 \n");
    printf("3. 인원 수정 \n");
    printf("4. 인원 삭제 \n");
    printf("5. 출퇴근 확인 \n");
    printf("6. 인원 정보 저장 \n");
    printf("7. 인원 정보 검색 \n");
    printf("0. 종료 \n\n");
    printf("=> 메뉴를 선택해주세요. ");
    scanf("%d", &menu);
    return menu;
}

int addPrivacy(Privacy *s) // Create
{

    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("이름을 입력해주세요 =>\n");
        scanf("%s", s->name);
        printf("나이를 입력해주세요 =>\n");
        scanf("%d", &s->age);
        printf("전화번호를 입력해주세요 =>\n");
        scanf("%s", s->phone_num);
        printf("직책을 입력해주세요 =>\n");
        scanf("%s", s->position);
        printf("고유번호를 입력해주세요 =>\n");
        scanf("%d", &s->special_num);
        printf("비밀번호를 입력해주세요 =>\n");
        scanf("%s", s->pwd);
        printf("\n==> 추가되었습니다 <==\n");
        return 1;
    }
    else
    {
        printf("\nMasterkey 가 아닙니다!!\n");
        return 0;
    }
}
// Read 개인정보
void readPrivacy(Privacy *s, int count)
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        printf("\nNo Position Name Age  Phone_num    Speicial_num  Pwd \n");
        printf("====================================================\n");
        for (int i = 0; i < count; i++)
        {
            if (s[i].age == -1)
                continue;
            printf("%2d ", i + 1);
            read_OnePrivacy(s[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nMasterkey 가 아닙니다!!\n");
    }
}
void read_OnePrivacy(Privacy s)
{
    printf("%4s %6s %4d %10s %8d %10s\n", s.position, s.name, s.age, s.phone_num, s.special_num, s.pwd);
}
int updatePrivacy(Privacy *s) // Update
{
    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("새로운 이름을 입력해주세요 =>\n");
        scanf("%s", s->name);
        printf("새로운 나이를 입력해주세요 =>\n");
        scanf("%d", &s->age);
        printf("새로운 전화번호를 입력해주세요 =>\n");
        scanf("%s", s->phone_num);
        printf("새로운 직책을 입력해주세요 =>\n");
        scanf("%s", s->position);
        printf("새로운 비밀번호를 입력해주세요 =>\n");
        scanf("%s", s->pwd);
        printf("\n==> 수정되었습니다 <== \n");

        return 1;
    }
    else
    {
        printf("\nMasterkey가 아닙니다!!\n");
        return 0;
    }
}

int deletePrivacy(Privacy *s) // Delete
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        s->age = -1; //占쏙옙占싱곤옙 占쏙옙占쏙옙占쏙옙 占신댐옙 占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙占쏙옙
        return 1;
    }
    else
    {
        printf("\nMasterkey가 아닙니다!!\n");
        return 0;
    }
}

int askIndex(Privacy *s, int count)
{
    int answer;

    readPrivacy(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &answer);
    return answer;
}

void checkCommute(Privacy *s, int count)
{
    int num = 0;         //출퇴근 확인
    int flag = 0;        //고유번호와 비밀번호를 잘 입력했는지 확인
    int i = 0;           //반복문 변수
    int tmp_special_num; //임시 고유번호
    char tmp_pwd[30];    //임시 패스워드

    printf("출근이면 1을 입력하고 퇴근이면 2를 입력해주세요!\n");
    scanf("%d", &num);
    if (!(num == 1 || num == 2))
    {
        printf("번호를 잘못 누르셨습니다.\n");
        return;
    }
    printf("고유번호를 입력해주세요!\n");
    scanf("%d", &tmp_special_num);
    getchar();
    printf("비밀번호를 입력해주세요!\n");
    scanf("%s", tmp_pwd);

    for (; i < count; i++)
    {
        if (s[i].special_num == tmp_special_num)
        {
            if (strcmp(s[i].pwd, tmp_pwd) == 0)
            {
                flag = 1; //찾았다는 의미
                break;
            }
        }
    }

    if (flag == 1 && num == 1)
    { //도착시간을 저장하면 됨
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("시간을 성공적으로 저장하였습니다\n");
        return;
    }
    if (flag == 1 && num == 2)
    { //떠난시간을 저장하면 됨
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("시간을 성공적으로 저장하였습니다\n");
        return;
    }
}

void saveData(Privacy *s, int count)
{
    FILE *file;
    file = fopen("log.txt", "wt");

    fprintf(file, "이름\t직책\t나이\t출근시간\t퇴근시간\n");
    for (int i = 0; i < count; i++)
    {
        if (s[i].age == -1)
            continue;
        fprintf(file, "%s\t%s\t%d\t\t%d:%d:%d\t%d:%d:%d", s[i].name, s[i].position, s[i].age, s[i].arrive_time_hour, s[i].arrive_time_min, s[i].arrive_time_sec, s[i].leave_time_hour, s[i].leave_time_min, s[i].leave_time_sec);
    }
    fclose(file);
    printf("\n ==> 저장되었습니다. <==\n");
}

int loadData(Privacy *s)
{
    int count = 0;
    FILE *file;
    file = fopen("log.txt", "rt");
    if (file == NULL)
    {
        printf("\n==> 파일이 존재하지 않습니다 <==\n");
        return 0;
    }
    else
    {
        fscanf(file, "이름\t직책\t나이\t출근시간\t퇴근시간\n");
        while (!feof(file))
        {
            if (s[count].age == -1)
                continue;
            int num = fscanf(file, "%s\t%s\t%d\t%d %d %d\t%d %d %d", s[count].name, s[count].position, &s[count].age, &s[count].arrive_time_hour, &s[count].arrive_time_min, &s[count].arrive_time_sec, &s[count].leave_time_hour, &s[count].leave_time_min, &s[count].leave_time_sec);
            if (num != 9)
                break;
            count++;
        }
    }
    fclose(file);

    if (count > 0)
        printf("\n==> 로딩에 성공하였습니다 <==\n");
    else
        printf("\n==> 파일이 존재하지 않습니다 <==\n");
    return count;
}

void findPrivacy(Privacy *s, int count)
{
    int scnt = 0;
    char search[20];
    int num;
    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("검색하실 메뉴를 선택해주세요 (1:이름|2:직책)\n");
        scanf("%d", &num);
        if (!(num == 1 || num == 2))
        {
            printf("error: 번호를 잘못 누르셨습니다.\n");
            return;
        }

        if (num == 1)
        {
            printf("검색할 이름을 입력해주세요. \n");
            scanf("%s", search);
            printf("\nNo Position Name Age  Phone_num    Speicial_num  Pwd \n");
            printf("====================================================\n");
            for (int i = 0; i < count; i++)
            {
                if (s[i].age == -1)
                    continue;
                if (strstr(s[i].name, search))
                {
                    printf("%2d", i + 1);
                    read_OnePrivacy(s[i]);
                    scnt++;
                }
            }
            if (scnt == 0)
                printf("\n==> 검색된 데이터 없음 <==\n");
        }
        if (num == 2)
        {
            printf("검색할 직책을 입력해주세요. \n");
            scanf("%s", search);
            printf("\nNo Position Name Age  Phone_num    Speicial_num  Pwd \n");
            printf("====================================================\n");
            for (int i = 0; i < count; i++)
            {
                if (s[i].age == -1)
                    continue;
                if (strstr(s[i].position, search))
                {
                    printf("%2d", i + 1);
                    read_OnePrivacy(s[i]);
                    scnt++;
                }
            }
            if (scnt == 0)
                printf("\n==> 검색된 데이터 없음 <==\n");
        }
    }
    else
    {
        printf("\nMasterkey가 아닙니다!!\n");
    }
}
