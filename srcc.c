#include "srcc.h"

char masterkey[30] = {"1234 abcd!"};

int checkMasterkey()
{
    char temp_mk[30];
    printf("����Ͻ÷��� Masterkey�� �Է����ּ��� =>\n");
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
    printf("\n***** ��� ���� �޴� *****\n");
    printf("1. �ο� ��ȸ \n");
    printf("2. �ο� �߰� \n");
    printf("3. �ο� ���� \n");
    printf("4. �ο� ���� \n");
    printf("0. ���� \n\n");
    printf("=> �޴��� �������ּ���. ");
    scanf("%d", &menu);
    return menu;
}

int addPrivacy(Privacy *s) // Create
{

    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("�̸��� �Է����ּ��� =>");
        scanf("%s", s->name);
        printf("���̸� �Է����ּ��� =>");
        scanf("%d", &s->age);
        printf("��ȭ��ȣ�� �Է����ּ��� =>");
        scanf("%s", s->phone_num);
        printf("��å�� �Է����ּ��� =>");
        scanf("%s", s->position);
        printf("������ȣ�� �Է����ּ��� =>");
        scanf("%d", &s->special_num);
        printf("��й�ȣ�� �Է����ּ��� =>");
        scanf("%s", s->pwd);

        return 1;
    }
    else
    {
        printf("\nMasterkey �� �ƴմϴ�!!\n");
        return 0;
    }
}
// Read �Լ�
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
        printf("\nMasterkey�� �ƴմϴ�!!\n");
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
        printf("���ο� �̸��� �Է����ּ��� =>");
        scanf("%s", s->name);
        printf("���ο� ���̸� �Է����ּ��� =>");
        scanf("%d", &s->age);
        printf("���ο� ��ȭ��ȣ�� �Է����ּ��� =>");
        scanf("%s", s->phone_num);
        printf("���ο� ��å�� �Է����ּ��� =>");
        scanf("%s", s->position);
        printf("���ο� ��й�ȣ�� �Է����ּ��� =>");
        scanf("%s", s->pwd);
        printf("==> �����Ǿ����ϴ� <== \n");

        return 1;
    }
    else
    {
        printf("\nMasterkey�� �ƴմϴ�!!\n");
        return 0;
    }
}

int deletePrivacy(Privacy *s) // Delete
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        s->age = -1; //���̰� ������ �Ŵ� ���� ���� ����
        return 1;
    }
    else
    {
        printf("\nMasterkey�� �ƴմϴ�!!\n");
        return 0;
    }
}

int askIndex(Privacy *s, int count)
{
    int answer;

    readPrivacy(s, count);
    printf("��ȣ�� (��� :0)? ");
    scanf("%d", &answer);
    return answer;
}

void checkCommute(Privacy *s, int count){
    int num=0;//출퇴근 확인
    int flag=0;//고유번호와 비밀번호를 잘 입력했는지 확인
    int i=0;//반복문 변수
    int tmp_special_num;//임시 고유번호 
    char tmp_pwd[30];//임시 패스워드

    printf("출근이면 1을 입력하고 퇴근이면 2를 입력해주세요!\n");
    scnaf("%d",&num);
    if(!(num==1||num==2)){
        printf("번호를 잘못 누르셨습니다.\n");
        return ;
    }
    printf("고유번호를 입력해주세요!\n");
    scanf("%d",&tmp_special_num);
    getchar();
    printf("비밀번호를 입력해주세요!\n");
    scanf("%s",tmp_pwd);

    for(; i<count; i++){
        if(s[i].special_num == tmp_special_num){
            if(strcmp(s[i].pwd,tmp_pwd)==0){
                flag =1;//찾았다는 의미
                break;
            }
        }
    }

    if(flag==1&&num==1){//도착시간을 저장하면 됨
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min  = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("시간을 성공적으로 저장하였습니다\n");
        return ;
    }
    if(flag==1&&num==2){//떠난시간을 저장하면 됨
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min  = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("시간을 성공적으로 저장하였습니다\n");
        return ;
    }
    
}