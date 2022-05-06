#include "srcc.h"

int addPrivacy(Privacy *s){
    printf("이름은? ");
    scanf("%s",s->name);
    printf("나이는? ");
    scanf("%d",&s->age);
    printf("전화번호는? ");
    scanf("%s",s->phone_num);
    printf("직책은?");
    scanf("%s",s->position);
    printf("고유번호는?");
    scanf("%d",&s->special_num);
    printf("비밀번호는?");
    scanf("%s",s->pwd);

    return 1;
}
int delete_Privacy(Privacy *s){
    s->age = -1;//나이가 음수인 거는 말이 되지 않음
  return 1;
}
