#include <stdio.h>
#include <ctype.h>
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


int main()
{
    char a=' ';
    while (a != 0x7f){
        a=mygetch();
        if (isdigit(a)){
            int b=a-'0'+1;
            printf("%d",b%10);
        } else{
            printf("%c",a);
        }
    }
    return 0;
}