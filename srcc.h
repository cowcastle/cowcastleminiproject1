#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char name[20];
    int age;
    char position[20]; //��å
    char phone_num[20];
    int special_num; //������ȣ
    char pwd[30];
    char fixed_time[20];  //������ ��� �ð�

    int arrive_time_hour; //��� �ð�
    int arrive_time_min; 
    int arrive_time_sec; 
    
    int leave_time_hour;  //��� �ð�
    int leave_time_min;
    int leave_time_sec;
} Privacy;

int addPrivacy(Privacy *s);              // 1��° ��� ���� �߰��ϴ� �Լ�
void readPrivacy(Privacy *s, int count); // 13��° ��� ���� ���� �Լ�
void read_OnePrivacy(Privacy s);         // 14��° �� ����� ������ ���� �Լ�
int updatePrivacy(Privacy *s);           // 3��° ��� ���� �����ϴ� �Լ�
int deletePrivacy(Privacy *s);           // 2��° ��� ���� �����ϴ� �Լ�
void saveData(Privacy *s, int count);    // 4��° ���� ���� ���� �Լ�
int loadData(Privacy *s);                // 5��° ���Ͽ� �ִ� �����͸� �ҷ����� �Լ�
int selectMenu();                        // 6��° ��� ���� ��ü�޴�
void checkCommute(Privacy *s,int count);           // 7��° ����� �����ϴ� �Լ�
void seeTime(Privacy *s);                // 8��° ����� ��Ϻ��� �Լ�
void expressWrong(Privacy *s);           // 9��° ����ϰ� ��� �߸� ����� �� ǥ�����ִ� �Լ�
int checkLate(Privacy *s);               // 10��° ������ ��� üũ �Լ�
int askIndex(Privacy *s, int count);     // 12��° ����� �����ϴ� �Լ�
int checkMasterkey();                    // 15��° ����� ���� �߰�,����,����,�д� ���� ��ȣ�� ���� �� ������ �Ұǵ� �� ��ȣ�� �����ϴ� ��
