#include "srcc.h"

char masterkey[30] = {"1234 abcd!"};

int checkMasterkey()
{
    char temp_mk[30];
    printf("占쏙옙占쏙옙絿첨占쏙옙占� Masterkey占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>\n");
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
    printf("\n***** 占쏙옙占� 占쏙옙占쏙옙 占쌨댐옙 *****\n");
    printf("1. 占싸울옙 占쏙옙회 \n");
    printf("2. 占싸울옙 占쌩곤옙 \n");
    printf("3. 占싸울옙 占쏙옙占쏙옙 \n");
    printf("4. 占싸울옙 占쏙옙占쏙옙 \n");
    printf("0. 占쏙옙占쏙옙 \n\n");
    printf("=> 占쌨댐옙占쏙옙 占쏙옙占쏙옙占쏙옙占쌍쇽옙占쏙옙. ");
    scanf("%d", &menu);
    return menu;
}

int addPrivacy(Privacy *s) // Create
{

    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("占싱몌옙占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->name);
        printf("占쏙옙占싱몌옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%d", &s->age);
        printf("占쏙옙화占쏙옙호占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->phone_num);
        printf("占쏙옙책占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->position);
        printf("占쏙옙占쏙옙占쏙옙호占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%d", &s->special_num);
        printf("占쏙옙橘占싫ｏ옙占� 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->pwd);

        return 1;
    }
    else
    {
        printf("\nMasterkey 占쏙옙 占싣닙니댐옙!!\n");
        return 0;
    }
}
// Read 占쌉쇽옙
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
        printf("\nMasterkey占쏙옙 占싣닙니댐옙!!\n");
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
        printf("占쏙옙占싸울옙 占싱몌옙占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->name);
        printf("占쏙옙占싸울옙 占쏙옙占싱몌옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%d", &s->age);
        printf("占쏙옙占싸울옙 占쏙옙화占쏙옙호占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->phone_num);
        printf("占쏙옙占싸울옙 占쏙옙책占쏙옙 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->position);
        printf("占쏙옙占싸울옙 占쏙옙橘占싫ｏ옙占� 占쌉뤄옙占쏙옙占쌍쇽옙占쏙옙 =>");
        scanf("%s", s->pwd);
        printf("==> 占쏙옙占쏙옙占실억옙占쏙옙占싹댐옙 <== \n");

        return 1;
    }
    else
    {
        printf("\nMasterkey占쏙옙 占싣닙니댐옙!!\n");
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
        printf("\nMasterkey占쏙옙 占싣닙니댐옙!!\n");
        return 0;
    }
}

int askIndex(Privacy *s, int count)
{
    int answer;

    readPrivacy(s, count);
    printf("占쏙옙호占쏙옙 (占쏙옙占� :0)? ");
    scanf("%d", &answer);
    return answer;
}

void checkCommute(Privacy *s, int count)
{
    int num = 0;         //異쒗눜洹� �솗�씤
    int flag = 0;        //怨좎쑀踰덊샇��� 鍮꾨��踰덊샇瑜� �옒 �엯�젰�뻽�뒗吏� �솗�씤
    int i = 0;           //諛섎났臾� 蹂��닔
    int tmp_special_num; //�엫�떆 怨좎쑀踰덊샇
    char tmp_pwd[30];    //�엫�떆 �뙣�뒪�썙�뱶

    printf("異쒓렐�씠硫� 1�쓣 �엯�젰�븯怨� �눜洹쇱씠硫� 2瑜� �엯�젰�빐二쇱꽭�슂!\n");
    scnaf("%d", &num);
    if (!(num == 1 || num == 2))
    {
        printf("踰덊샇瑜� �옒紐� �늻瑜댁뀲�뒿�땲�떎.\n");
        return;
    }
    printf("怨좎쑀踰덊샇瑜� �엯�젰�빐二쇱꽭�슂!\n");
    scanf("%d", &tmp_special_num);
    getchar();
    printf("鍮꾨��踰덊샇瑜� �엯�젰�빐二쇱꽭�슂!\n");
    scanf("%s", tmp_pwd);

    for (; i < count; i++)
    {
        if (s[i].special_num == tmp_special_num)
        {
            if (strcmp(s[i].pwd, tmp_pwd) == 0)
            {
                flag = 1; //李얠븯�떎�뒗 �쓽誘�
                break;
            }
        }
    }

    if (flag == 1 && num == 1)
    { //�룄李⑹떆媛꾩쓣 ����옣�븯硫� �맖
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("�떆媛꾩쓣 �꽦怨듭쟻�쑝濡� ����옣�븯����뒿�땲�떎\n");
        return;
    }
    if (flag == 1 && num == 2)
    { //�뼚�궃�떆媛꾩쓣 ����옣�븯硫� �맖
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("�떆媛꾩쓣 �꽦怨듭쟻�쑝濡� ����옣�븯����뒿�땲�떎\n");
        return;
    }
}