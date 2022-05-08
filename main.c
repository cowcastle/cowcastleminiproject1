#include "srcc.h"

int main(void){

    Privacy s[20];
    int count = 0, menu;
    int index=0;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readPrivacy(s,index);
        }
        else if (menu == 2){
            if(count<=20){//특정개수를 초과하면 안됨
                count += addPrivacy(&s[index++]);//특정 배열의 주소를 보내주기 때문에 &을 꼭 써야함!!
            }
            else{
                printf("더 이상 추가할 수 없습니다.\n");
            }
        }
        else if (menu == 3){
            int answer = askIndex(s,index);
            if(answer!=0){
                updatePrivacy(&s[answer-1]);//answer-1을 하는 이유 index가 0부터 시작하기 때문
            }
            else{
                printf("수정할 수 없습니다.\n");
            }
        }
        else if (menu == 4){
            int answer = askIndex(s,index);
            if(answer==0){
                printf("=> 취소됨!\n");
                continue;
            }
            else{
                int delete;
                printf("정말로 삭제하시겠습니까?(삭제 :1)");
                scanf("%d",&delete);
                if(delete==1){
                    if(deletePrivacy(&s[answer-1])){
                        count--;
                        printf("=> 삭제됨!\n");
                    }
                }
            }
        }
        
    }
    
    printf("종료됨!\n");
    return 0;
}