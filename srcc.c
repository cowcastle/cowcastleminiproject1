#include "srcc.h"

char masterkey[30] = {"1234 abcd!"};

int checkMasterkey()
{
    char temp_mk[30];
    printf("? ??? ??็ตฟ์ฒจ? ??? ๏ฟ? Masterkey? ?? ? ?๋ค์? ??? ??ฝ?? ?? =>\n");
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
    printf("\n***** ? ??? ๏ฟ? ? ??? ?? ? ?จ?? *****\n");
    printf("1. ? ?ธ?ธ? ? ??? \n");
    printf("2. ? ?ธ?ธ? ? ?ฉ๊ณค์ \n");
    printf("3. ? ?ธ?ธ? ? ??? ?? \n");
    printf("4. ? ?ธ?ธ? ? ??? ?? \n");
    printf("0. ? ??? ?? \n\n");
    printf("=> ? ?จ??? ?? ? ??? ??? ??? ??ฝ?? ??. ");
    scanf("%d", &menu);
    return menu;
}

int addPrivacy(Privacy *s) // Create
{

    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("? ?ฑ๋ช์? ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->name);
        printf("? ??? ?ฑ๋ช์ ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%d", &s->age);
        printf("? ???? ???ธ? ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->phone_num);
        printf("? ??์ฑๅ ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->position);
        printf("? ??? ??? ???ธ? ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%d", &s->special_num);
        printf("? ??ๆฉๅ ?ซ๏ฝ์? ๏ฟ? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->pwd);

        return 1;
    }
    else
    {
        printf("\nMasterkey ? ?? ? ?ฃ????!!\n");
        return 0;
    }
}
// Read ? ??ฝ?
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
        printf("\nMasterkey? ?? ? ?ฃ????!!\n");
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
        printf("? ??? ?ธ?ธ? ? ?ฑ๋ช์? ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->name);
        printf("? ??? ?ธ?ธ? ? ??? ?ฑ๋ช์ ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%d", &s->age);
        printf("? ??? ?ธ?ธ? ? ???? ???ธ? ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->phone_num);
        printf("? ??? ?ธ?ธ? ? ??์ฑๅ ?? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->position);
        printf("? ??? ?ธ?ธ? ? ??ๆฉๅ ?ซ๏ฝ์? ๏ฟ? ? ?๋ค์? ??? ??ฝ?? ?? =>");
        scanf("%s", s->pwd);
        printf("==> ? ??? ??? ?ค?ต?? ??? ?น?? <== \n");

        return 1;
    }
    else
    {
        printf("\nMasterkey? ?? ? ?ฃ????!!\n");
        return 0;
    }
}

int deletePrivacy(Privacy *s) // Delete
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        s->age = -1; //? ??? ?ฑ๊ณค์ ? ??? ??? ?? ? ? ?? ? ??? ?? ? ??? ?? ? ??? ??
        return 1;
    }
    else
    {
        printf("\nMasterkey? ?? ? ?ฃ????!!\n");
        return 0;
    }
}

int askIndex(Privacy *s, int count)
{
    int answer;

    readPrivacy(s, count);
    printf("? ???ธ? ?? (? ??? ๏ฟ? :0)? ");
    scanf("%d", &answer);
    return answer;
}

void checkCommute(Privacy *s, int count)
{
    int num = 0;         //?ฐ??ๆดน๏ฟฝ ๏ฟฝ์๏ฟฝ์ค
    int flag = 0;        //??จ์ข???่ธฐ๋?๏ฟฝ๏ฟฝ๏ฟ? ?ฎ๊พจ๏ฟฝ๏ฟฝ่ธฐ???๏ฟ? ๏ฟฝ์ ๏ฟฝ์ฏ๏ฟฝ์ ฐ๏ฟฝ๋ปฝ๏ฟฝ๋๏ง๏ฟฝ ๏ฟฝ์๏ฟฝ์ค
    int i = 0;           //่ซ์?ฌ?พ๏ฟ? ่น๏ฟฝ๏ฟฝ๋
    int tmp_special_num; //๏ฟฝ์ซ๏ฟฝ๋ ??จ์ข???่ธฐ๋?
    char tmp_pwd[30];    //๏ฟฝ์ซ๏ฟฝ๋ ๏ฟฝ๋ฃ๏ฟฝ๋ช๏ฟฝ์๏ฟฝ๋ฑถ

    printf("?ฐ?? ๏ฟฝ์ ๏ง๏ฟฝ 1๏ฟฝ์ฃ ๏ฟฝ์ฏ๏ฟฝ์ ฐ๏ฟฝ๋ธฏ??จ๏ฟฝ ๏ฟฝ๋ๆดน์ฑ? ๏ง๏ฟฝ 2?๏ฟ? ๏ฟฝ์ฏ๏ฟฝ์ ฐ๏ฟฝ๋นไบ์ฑ๊ฝ?๏ฟฝ์!\n");
    scnaf("%d", &num);
    if (!(num == 1 || num == 2))
    {
        printf("่ธฐ๋??๏ฟ? ๏ฟฝ์๏ง๏ฟฝ ๏ฟฝ๋ป????ฒ๏ฟฝ?ฟ๏ฟฝ๋ฒ๏ฟฝ๋.\n");
        return;
    }
    printf("??จ์ข???่ธฐ๋??๏ฟ? ๏ฟฝ์ฏ๏ฟฝ์ ฐ๏ฟฝ๋นไบ์ฑ๊ฝ?๏ฟฝ์!\n");
    scanf("%d", &tmp_special_num);
    getchar();
    printf("?ฎ๊พจ๏ฟฝ๏ฟฝ่ธฐ???๏ฟ? ๏ฟฝ์ฏ๏ฟฝ์ ฐ๏ฟฝ๋นไบ์ฑ๊ฝ?๏ฟฝ์!\n");
    scanf("%s", tmp_pwd);

    for (; i < count; i++)
    {
        if (s[i].special_num == tmp_special_num)
        {
            if (strcmp(s[i].pwd, tmp_pwd) == 0)
            {
                flag = 1; //๏งก์ ๋ธ?๏ฟฝ๋๏ฟฝ๋ ๏ฟฝ์ฝ่ช๏ฟฝ
                break;
            }
        }
    }

    if (flag == 1 && num == 1)
    { //๏ฟฝ๋ฃ๏งกโน?ๅช๊พฉ?ฃ ๏ฟฝ๏ฟฝ๏ฟฝ๏ฟฝ?ฃ๏ฟฝ๋ธฏ๏ง๏ฟฝ ๏ฟฝ๋ง
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("๏ฟฝ๋ๅช๊พฉ?ฃ ๏ฟฝ๊ฝฆ??จ๋ญ?ป๏ฟฝ์ๆฟก๏ฟฝ ๏ฟฝ๏ฟฝ๏ฟฝ๏ฟฝ?ฃ๏ฟฝ๋ธฏ๏ฟฝ๏ฟฝ๏ฟฝ๏ฟฝ?ฟ๏ฟฝ๋ฒ๏ฟฝ๋\n");
        return;
    }
    if (flag == 1 && num == 2)
    { //๏ฟฝ๋ผ๏ฟฝ๊ถ๏ฟฝ๋ๅช๊พฉ?ฃ ๏ฟฝ๏ฟฝ๏ฟฝ๏ฟฝ?ฃ๏ฟฝ๋ธฏ๏ง๏ฟฝ ๏ฟฝ๋ง
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("๏ฟฝ๋ๅช๊พฉ?ฃ ๏ฟฝ๊ฝฆ??จ๋ญ?ป๏ฟฝ์ๆฟก๏ฟฝ ๏ฟฝ๏ฟฝ๏ฟฝ๏ฟฝ?ฃ๏ฟฝ๋ธฏ๏ฟฝ๏ฟฝ๏ฟฝ๏ฟฝ?ฟ๏ฟฝ๋ฒ๏ฟฝ๋\n");
        return;
    }
}

void seeTime(Privacy *s, int count)
{
    int scnt = 0;
    char search[20];

    printf("ฐหป๖วา ภฬธง? ");
    scanf("%s", search);
    printf("*********************\n");
    for (int i = 0; i < count; i++)
    {
        if (s[i].age == -1)
            continue;
        if (strstr(s[i].name, search))
        {
            printf("%2d", i + 1);
            readScore(s[i]);
            scnt++;
        }
    }
    if (scnt == 0)
        printf("==> ฐหป๖ตศ ตฅภฬลอ พ๘ภฝ");
    printf("\n");
}