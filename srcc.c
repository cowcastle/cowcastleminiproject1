#include "srcc.h"

char masterkey[30] = {"12345"};

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
    printf("5. ����� �Է� \n");
    printf("6. ����� ��ȸ \n");
    printf("7. �����  ���� ���� \n");
    printf("8. �ο� ���� �˻� \n");
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
        printf("�̸��� �Է����ּ��� =>\n");
        scanf("%s", s->name);
        printf("���̸� �Է����ּ��� =>\n");
        scanf("%d", &s->age);
        printf("��ȭ��ȣ�� �Է����ּ��� =>\n");
        scanf("%s", s->phone_num);
        printf("��å�� �Է����ּ��� =>\n");
        scanf("%s", s->position);
        printf("������ȣ�� �Է����ּ��� =>\n");
        scanf("%d", &s->special_num);
        printf("��й�ȣ�� �Է����ּ��� =>\n");
        scanf("%s", s->pwd);
        printf("\n==> �߰��Ǿ����ϴ� <==\n");
        return 1;
    }
    else
    {
        printf("\nMasterkey �� �ƴմϴ�!!\n");
        return 0;
    }
}
// Read ��������
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
        printf("\nMasterkey �� �ƴմϴ�!!\n");
    }
}

void readCommute(Privacy *s, int count)
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        printf("�̸�\t��å\t����\t��ٽð�\t��ٽð�\n");
        printf("===============================================\n");
        for (int i = 0; i < count; i++)
        {
            if (s[i].age == -1)
                continue;
            printf("%s\t%s\t%d\t%d:%d:%d\t%d:%d:%d", s[i].name, s[i].position, s[i].age, s[i].arrive_time_hour, s[i].arrive_time_min, s[i].arrive_time_sec, s[i].leave_time_hour, s[i].leave_time_min, s[i].leave_time_sec);
        }
        printf("\n");
    }
    else
    {
        printf("\nMasterkey �� �ƴմϴ�!!\n");
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
        printf("���ο� �̸��� �Է����ּ��� =>\n");
        scanf("%s", s->name);
        printf("���ο� ���̸� �Է����ּ��� =>\n");
        scanf("%d", &s->age);
        printf("���ο� ��ȭ��ȣ�� �Է����ּ��� =>\n");
        scanf("%s", s->phone_num);
        printf("���ο� ��å�� �Է����ּ��� =>\n");
        scanf("%s", s->position);
        printf("���ο� ��й�ȣ�� �Է����ּ��� =>\n");
        scanf("%s", s->pwd);
        printf("\n==> �����Ǿ����ϴ� <== \n");

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

void checkCommute(Privacy *s, int count)
{
    int num = 0;         //����� Ȯ��
    int flag = 0;        //������ȣ�� ��й�ȣ�� �� �Է��ߴ��� Ȯ��
    int i = 0;           //�ݺ��� ����
    int tmp_special_num; //�ӽ� ������ȣ
    char tmp_pwd[30];    //�ӽ� �н�����

    printf("����̸� 1�� �Է��ϰ� ����̸� 2�� �Է����ּ���!\n");
    scanf("%d", &num);
    if (!(num == 1 || num == 2))
    {
        printf("��ȣ�� �߸� �����̽��ϴ�.\n");
        return;
    }
    printf("������ȣ�� �Է����ּ���!\n");
    scanf("%d", &tmp_special_num);
    getchar();
    printf("��й�ȣ�� �Է����ּ���!\n");
    scanf("%s", tmp_pwd);

    for (; i < count; i++)
    {
        if (s[i].special_num == tmp_special_num)
        {
            if (strcmp(s[i].pwd, tmp_pwd) == 0)
            {
                flag = 1; //ã�Ҵٴ� �ǹ�
                break;
            }
        }
    }

    if (flag == 1 && num == 1)
    { //�����ð��� �����ϸ� ��
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("�ð��� ���������� �����Ͽ����ϴ�\n");
        return;
    }
    if (flag == 1 && num == 2)
    { //�����ð��� �����ϸ� ��
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("�ð��� ���������� �����Ͽ����ϴ�\n");
        return;
    }
}

void saveData(Privacy *s, int count)
{
    FILE *file;
    file = fopen("log.txt", "wt");

    for (int i = 0; i < count; i++)
    {
        if (s[i].age == -1)
            continue;
        fprintf(file, "%s\t%s\t%d\t\t%d:%d:%d\t%d:%d:%d", s[i].name, s[i].position, s[i].age, s[i].arrive_time_hour, s[i].arrive_time_min, s[i].arrive_time_sec, s[i].leave_time_hour, s[i].leave_time_min, s[i].leave_time_sec);
    }
    fclose(file);
    printf("\n ==> ����Ǿ����ϴ�. <==\n");
}

int loadData(Privacy *s)
{
    int count = 0;
    int i = 0;
    FILE *file;
    file = fopen("log.txt", "rt");
    if (file == NULL)
    {
        printf("\n==> ������ �������� �ʽ��ϴ� <==\n");
        return 0;
    }
    else
    {
        for (; i < 100; i++)
        {
            if (s[count].age == -1)
                continue;
            fscanf(file, "%s\t%s\t%d\t\t%d %d %d\t%d %d %d", s[i].name, s[i].position, &s[i].age, &s[i].arrive_time_hour, &s[i].arrive_time_min, &s[i].arrive_time_sec, &s[i].leave_time_hour, &s[i].leave_time_min, &s[i].leave_time_sec);
            if (feof(file))
                break;
        }
    }
    if (file == NULL)
    {
        printf("\n=> ���� ����\n");
        i = 0;
    }
    else if (file != NULL)
    {
        printf("\n=> �ε� ����!\n");
    }
    fclose(file);
    return i;
}

void findPrivacy(Privacy *s, int count)
{
    int scnt = 0;
    char search[20];
    int num;
    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("�˻��Ͻ� �޴��� �������ּ��� (1:�̸�|2:��å)\n");
        scanf("%d", &num);
        if (!(num == 1 || num == 2))
        {
            printf("error: ��ȣ�� �߸� �����̽��ϴ�.\n");
            return;
        }

        if (num == 1)
        {
            printf("�˻��� �̸��� �Է����ּ���. \n");
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
                printf("\n==> �˻��� ������ ���� <==\n");
        }
        if (num == 2)
        {
            printf("�˻��� ��å�� �Է����ּ���. \n");
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
                printf("\n==> �˻��� ������ ���� <==\n");
        }
    }
    else
    {
        printf("\nMasterkey�� �ƴմϴ�!!\n");
    }
}
