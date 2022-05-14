#include "srcc.h"

char masterkey[30] = {"1234 abcd!"};

int checkMasterkey()
{
    char temp_mk[30];
    printf("? ?™?˜™? ?™?˜™çµ¿ì²¨? ?™?˜™? ï¿? Masterkey? ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>\n");
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
    printf("\n***** ? ?™?˜™? ï¿? ? ?™?˜™? ?™?˜™ ? ?Œ¨?Œ?˜™ *****\n");
    printf("1. ? ?‹¸?š¸?˜™ ? ?™?˜™?šŒ \n");
    printf("2. ? ?‹¸?š¸?˜™ ? ?Œ©ê³¤ì˜™ \n");
    printf("3. ? ?‹¸?š¸?˜™ ? ?™?˜™? ?™?˜™ \n");
    printf("4. ? ?‹¸?š¸?˜™ ? ?™?˜™? ?™?˜™ \n");
    printf("0. ? ?™?˜™? ?™?˜™ \n\n");
    printf("=> ? ?Œ¨?Œ?˜™? ?™?˜™ ? ?™?˜™? ?™?˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™. ");
    scanf("%d", &menu);
    return menu;
}

int addPrivacy(Privacy *s) // Create
{

    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("? ?‹±ëªŒì˜™? ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->name);
        printf("? ?™?˜™? ?‹±ëªŒì˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%d", &s->age);
        printf("? ?™?˜™?™”? ?™?˜™?˜¸? ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->phone_num);
        printf("? ?™?˜™ì±…å ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->position);
        printf("? ?™?˜™? ?™?˜™? ?™?˜™?˜¸? ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%d", &s->special_num);
        printf("? ?™?˜™æ©˜å ?‹«ï½ì˜™? ï¿? ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->pwd);

        return 1;
    }
    else
    {
        printf("\nMasterkey ? ?™?˜™ ? ?‹£?‹™?‹ˆ?Œ?˜™!!\n");
        return 0;
    }
}
// Read ? ?Œ‰?‡½?˜™
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
        printf("\nMasterkey? ?™?˜™ ? ?‹£?‹™?‹ˆ?Œ?˜™!!\n");
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
        printf("? ?™?˜™? ?‹¸?š¸?˜™ ? ?‹±ëªŒì˜™? ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->name);
        printf("? ?™?˜™? ?‹¸?š¸?˜™ ? ?™?˜™? ?‹±ëªŒì˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%d", &s->age);
        printf("? ?™?˜™? ?‹¸?š¸?˜™ ? ?™?˜™?™”? ?™?˜™?˜¸? ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->phone_num);
        printf("? ?™?˜™? ?‹¸?š¸?˜™ ? ?™?˜™ì±…å ?™?˜™ ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->position);
        printf("? ?™?˜™? ?‹¸?š¸?˜™ ? ?™?˜™æ©˜å ?‹«ï½ì˜™? ï¿? ? ?Œ‰ë¤„ì˜™? ?™?˜™? ?Œ?‡½?˜™? ?™?˜™ =>");
        scanf("%s", s->pwd);
        printf("==> ? ?™?˜™? ?™?˜™? ?‹¤?–µ?˜™? ?™?˜™? ?‹¹?Œ?˜™ <== \n");

        return 1;
    }
    else
    {
        printf("\nMasterkey? ?™?˜™ ? ?‹£?‹™?‹ˆ?Œ?˜™!!\n");
        return 0;
    }
}

int deletePrivacy(Privacy *s) // Delete
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        s->age = -1; //? ?™?˜™? ?‹±ê³¤ì˜™ ? ?™?˜™? ?™?˜™? ?™?˜™ ? ?‹ ?Œ?˜™ ? ?™?˜™? ?™?˜™ ? ?™?˜™? ?™?˜™ ? ?™?˜™? ?™?˜™
        return 1;
    }
    else
    {
        printf("\nMasterkey? ?™?˜™ ? ?‹£?‹™?‹ˆ?Œ?˜™!!\n");
        return 0;
    }
}

int askIndex(Privacy *s, int count)
{
    int answer;

    readPrivacy(s, count);
    printf("? ?™?˜™?˜¸? ?™?˜™ (? ?™?˜™? ï¿? :0)? ");
    scanf("%d", &answer);
    return answer;
}

void checkCommute(Privacy *s, int count)
{
    int num = 0;         //?•°?’—?ˆœæ´¹ï¿½ ï¿½ì†—ï¿½ì”¤
    int flag = 0;        //??¨ì¢???è¸°ëŠ?ƒ‡ï¿½ï¿½ï¿? ?®ê¾¨ï¿½ï¿½è¸°?Š?ƒ‡?‘œï¿? ï¿½ì˜’ ï¿½ì—¯ï¿½ì °ï¿½ë»½ï¿½ë’—ï§ï¿½ ï¿½ì†—ï¿½ì”¤
    int i = 0;           //è«›ì„?‚¬?‡¾ï¿? è¹‚ï¿½ï¿½ë‹”
    int tmp_special_num; //ï¿½ì—«ï¿½ë–† ??¨ì¢???è¸°ëŠ?ƒ‡
    char tmp_pwd[30];    //ï¿½ì—«ï¿½ë–† ï¿½ë™£ï¿½ë’ªï¿½ì™ï¿½ë±¶

    printf("?•°?’“? ï¿½ì” ï§ï¿½ 1ï¿½ì“£ ï¿½ì—¯ï¿½ì °ï¿½ë¸¯??¨ï¿½ ï¿½ëˆœæ´¹ì‡±?” ï§ï¿½ 2?‘œï¿? ï¿½ì—¯ï¿½ì °ï¿½ë¹äºŒì‡±ê½?ï¿½ìŠ‚!\n");
    scnaf("%d", &num);
    if (!(num == 1 || num == 2))
    {
        printf("è¸°ëŠ?ƒ‡?‘œï¿? ï¿½ì˜’ï§ï¿½ ï¿½ëŠ»?‘œ?Œ??²ï¿½?’¿ï¿½ë•²ï¿½ë–.\n");
        return;
    }
    printf("??¨ì¢???è¸°ëŠ?ƒ‡?‘œï¿? ï¿½ì—¯ï¿½ì °ï¿½ë¹äºŒì‡±ê½?ï¿½ìŠ‚!\n");
    scanf("%d", &tmp_special_num);
    getchar();
    printf("?®ê¾¨ï¿½ï¿½è¸°?Š?ƒ‡?‘œï¿? ï¿½ì—¯ï¿½ì °ï¿½ë¹äºŒì‡±ê½?ï¿½ìŠ‚!\n");
    scanf("%s", tmp_pwd);

    for (; i < count; i++)
    {
        if (s[i].special_num == tmp_special_num)
        {
            if (strcmp(s[i].pwd, tmp_pwd) == 0)
            {
                flag = 1; //ï§¡ì– ë¸?ï¿½ë–ï¿½ë’— ï¿½ì“½èª˜ï¿½
                break;
            }
        }
    }

    if (flag == 1 && num == 1)
    { //ï¿½ë£„ï§¡â‘¹?–†åª›ê¾©?“£ ï¿½ï¿½ï¿½ï¿½?˜£ï¿½ë¸¯ï§ï¿½ ï¿½ë§–
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("ï¿½ë–†åª›ê¾©?“£ ï¿½ê½¦??¨ë“­?Ÿ»ï¿½ì‘æ¿¡ï¿½ ï¿½ï¿½ï¿½ï¿½?˜£ï¿½ë¸¯ï¿½ï¿½ï¿½ï¿½?’¿ï¿½ë•²ï¿½ë–\n");
        return;
    }
    if (flag == 1 && num == 2)
    { //ï¿½ë¼šï¿½ê¶ƒï¿½ë–†åª›ê¾©?“£ ï¿½ï¿½ï¿½ï¿½?˜£ï¿½ë¸¯ï§ï¿½ ï¿½ë§–
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("ï¿½ë–†åª›ê¾©?“£ ï¿½ê½¦??¨ë“­?Ÿ»ï¿½ì‘æ¿¡ï¿½ ï¿½ï¿½ï¿½ï¿½?˜£ï¿½ë¸¯ï¿½ï¿½ï¿½ï¿½?’¿ï¿½ë•²ï¿½ë–\n");
        return;
    }
}

void seeTime(Privacy *s, int count)
{
    int scnt = 0;
    char search[20];

    printf("°Ë»öÇÒ ÀÌ¸§? ");
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
        printf("==> °Ë»öµÈ µ¥ÀÌÅÍ ¾øÀ½");
    printf("\n");
}