#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char name[20];
    int age;
    char position[20]; //직책
    char phone_num[20];
    int special_num; //고유번호
    char pwd[30];
    char fixed_time[20]; //정해진 출근 시간

    int arrive_time_hour; //출근 시간
    int arrive_time_min;
    int arrive_time_sec;

    int leave_time_hour; //퇴근 시간
    int leave_time_min;
    int leave_time_sec;
} Privacy;

int addPrivacy(Privacy *s);               // 1번째 사람 정보 추가하는 함수 (구현완료)
void readPrivacy(Privacy *s, int count);  // 13번째 사람 정보 보는 함수 (구현완료)
void readCommute(Privacy *s, int count);  // 13-1 이름 , 직위, 출퇴근시간
void read_OnePrivacy(Privacy s);          // 14번째 각 사람의 정보를 보는 함수 (구현완료)
int updatePrivacy(Privacy *s);            // 3번째 사람 정보 수정하는 함수 (구현완료)
int deletePrivacy(Privacy *s);            // 2번째 사람 정보 삭제하는 함수 (구현완료)
void saveData(Privacy *s, int count);     // 4번째 파일 정보 저장 함수 (구현완료)
int loadData(Privacy *s);                 // 5번째 파일에 있는 데이터를 불러오는 함수 (구현완료)
int selectMenu();                         // 6번째 출근 관련 전체메뉴 (구현완료)
void checkCommute(Privacy *s, int count); // 7번째 출퇴근 인증하는 함수 (구현완료)
// void seeTime(Privacy *s);                 // 8번째 출퇴근 기록보는 함수 -> findPrivacy로 합쳐짐
void expressWrong(Privacy *s);           // 9번째 출근하고 퇴근 잘못 찍었을 때 표현해주는 함수
int checkLate(Privacy *s);               // 10번째 지각한 사람 체크 함수
int askIndex(Privacy *s, int count);     // 12번째 사람을 선택하는 함수
void findPrivacy(Privacy *s, int count); // 8번째 함수 : 사람 정보 검색 함수 + 출퇴근 log 관리 (이름/직책으로 검색) (구현완료)
int checkMasterkey();                    // 15번째 사람의 정보 추가,삭제,수정,읽는 것을 암호가 맞을 때 실행을 할건데 그 암호를 설정하는 것 (구현완료)