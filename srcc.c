#include "srcc.h"

char masterkey[30]={"1234"};

int checkMasterkey(){
    char temp_mk[30];
    printf("계속 하실려면 masterkey를 입력해주세요!!\n");
    getchar();
    fgets(temp_mk,30,stdin);
    temp_mk[strlen(temp_mk) - 1] = '\0';

    //printf("[%s] [%s]",masterkey,temp_mk);

    int temp = strcmp(masterkey,temp_mk);

    if(temp==0) return 1;
    else return 0;
}

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

/*void currentTime() // 시간
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    FILE *file;
    file = fopen;
    fprintf(file, "%d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(file);
}
*/
int addPrivacy(Privacy *s) // Create
{   
 
    int temp = checkMasterkey();

    if(temp==1){
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
    else {
        printf("\nmasterkey가 아닙니다!!\n");
        return 0;
    }
}
// Read 함수
void readPrivacy(Privacy* s,int count){
    int temp = checkMasterkey();
    if(temp==1){
    printf("\nNo Position Name Age Phone_num Speicial_num Pwd \n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if(s[i].age==-1) continue;
        printf("%2d ",i+1);
        read_OnePrivacy(s[i]);
    }
    printf("\n");
    }
    else{
        printf("\nmasterkey가 아닙니다!!\n");
    }
}
void read_OnePrivacy(Privacy s){
        printf("%2s %5s %3d %12s %7d %20s\n",s.position,s.name,s.age,s.phone_num,s.special_num,s.pwd);
}
int updatePrivacy(Privacy *s) // Update
{
    int temp = checkMasterkey();

    if(temp==1){
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
    else{
        printf("\nmasterkey가 아닙니다!!\n");
        return 0;
    }

}

int deletePrivacy(Privacy *s) // Delete
{   
    int temp = checkMasterkey();
    if(temp == 1){
        s->age = -1; //나이가 음수인 거는 말이 되지 않음
        return 1;
    }
    else{
        printf("\nmasterkey가 아닙니다!!\n");
        return 0;
    }

}

int askIndex(Privacy *s,int count){
    int answer;

    readPrivacy(s,count);
    printf("번호는 (취소 :0)? ");
    scanf("%d",&answer);
    return answer;
}