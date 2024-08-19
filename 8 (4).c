#include <stdio.h>
#include <ctype.h>
#include <conio.h>
int main(){
    char a;
    int check_for_next=0, check_for_a=0;
    while (1){ //F8 - 0 и 66
        a=getch();
        if (a==0){
            check_for_a=1;
        }
        if (check_for_a==1){
            if (check_for_next==1){
                if (a==66){
                    break;
                } else{
                    check_for_next=0;
                    check_for_a=0;
                }
            } else{
                check_for_next=1;
            }
        }else{
            if (isalpha(a)){
                if (!isupper(a)){
                    printf("%c",a-32);
                } else{
                    printf("%c",a);
                }
            }
        }
    }
    return 0;
}