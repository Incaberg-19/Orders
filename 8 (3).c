#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main(void){
    char a;
    int check1=0,check2=0,check3=0;
    char symvol_1,symvol_2;
    int key_for_1=0,key_for_2=0;
    while(1){

        if (key_for_1==1 && key_for_2==1){
            printf("%c%c",symvol_2,symvol_1);
            key_for_1=0,key_for_2=0;
        }

        a=mygetch();
        if (a==27){
            check1=1;
        } else if(check1==1 && a==91){
            check2=1;
        } else if(check2==1 && a==54){
            check3=1;
        } else if(check3==1 && a==126){
            break;
        } else{
            check1=0,check2=0,check3=0;

            if (key_for_1==0 && key_for_2==0){
                symvol_1=a;
                key_for_1=1;
            } else if(key_for_2==0 && key_for_1==1){
                symvol_2=a;
                key_for_2=1;
            } 

        }

    }
    return 0;
}