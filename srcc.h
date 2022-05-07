#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int age;
    char position[20];//직책
    char phone_num[20];
    int special_num;//고유번호
    char pwd[30];
    char fixed_time[20];//정해진 출근 시간
    char arrive_time[20];//출근 시간
    char leave_time[20];//퇴근 시간
} Privacy;
 
int addPrivacy(Privacy *s);//1번째 사람 정보 추가하는 함수
void readPrivacy(Privacy *s,int count);//13번째 사람 정보 보는 함수
void read_OnePrivacy(Privacy s);
int updatePrivacy(Privacy *s);//3번째 사람 정보 수정하는 함수
int deletePrivacy(Privacy *s);//2번째 사람 정보 삭제하는 함수
void saveData(Privacy *s,int count);//4번째 파일 정보 저장 함수
int loadData(Privacy *s);//5번째 파일에 있는 데이터를 불러오는 함수
int selectMenu();//6번째 출근 관련 전체메뉴
void checkCommute(Privacy *s);//7번째 출퇴근 인증하는 함수
void seeTime(Privacy *s);//8번째 출퇴근 기록보는 함수
void expressWrong(Privacy *s);//9번째 출근하고 퇴근 잘못 찍었을 때 표현해주는 함수
int checkLate(Privacy *s);//10번째 지각한 사람 체크 함수
void currentTime();//11번째 현재 시간을 알려주고 기록하는 함수
int askIndex(Privacy *s,int count); //12번째 사람을 선택하는 함수
