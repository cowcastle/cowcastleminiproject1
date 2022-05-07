#include "srcc.h"

int selectMenu(){
    int menu;
    printf("\n*** 출근 관련 메뉴 ***\n");
    printf("1. 인원 조회\n");
    printf("2. 인원 추가\n");
    printf("3. 인원 수정\n");
    printf("4. 인원 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void currentTime() // 시간
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    FILE *file;
    file = fopen;
    fprintf(file, "%d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(file);
}

int addPrivacy(Privacy *s) // Create
{
    printf("이름을 입력해주세요 ");
    scanf("%s", s->name);
    printf("나이를 입력해주세요 ");
    scanf("%d", &s->age);
    printf("전화번호를 입력해주세요 ");
    scanf("%s", s->phone_num);
    printf("직책을 입력해주세요 ");
    scanf("%s", s->position);
    printf("고유번호를 입력해주세요 ");
    scanf("%d", &s->special_num);
    printf("비밀번호를 입력해주세요 ");
    scanf("%s", s->pwd);

    return 1;
}
// Read 함수
void readPrivacy(Privacy* s,int count){

    printf("\nNo Position Name Age Phone_num Speicial_num Pwd \n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if(s[i].age==-1) continue;
        printf("%2d ",i+1);
        read_OnePrivacy(s[i]);
    }
    printf("\n");
}

int updatePrivacy(Privacy *s) // Update
{
    printf("새로운 이름을 입력해주세요 ");
    scanf("%s", s->name);
    printf("새로운 나이를 입력해주세요 ");
    scanf("%d", &s->age);
    printf("새로운 전화번호를 입력해주세요 ");
    scanf("%s", s->phone_num);
    printf("새로운 직책을 입력해주세요 ");
    scanf("%s", s->position);
    printf("새로운 비밀번호를 입력해주세요 ");
    scanf("%s", s->pwd);
    printf("==> 수정되었습니다 <== \n");

    return 1;
}

int delete_Privacy(Privacy *s) // Delete
{
    s->age = -1; //나이가 음수인 거는 말이 되지 않음
    return 1;
}