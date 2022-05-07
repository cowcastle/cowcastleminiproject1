#include "srcc.h"

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