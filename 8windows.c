#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    char a=' ';
    while (a!=8){
    //пока введённая клавиша не равна порядкову номеру 8(backspace) продолжаем цикл
        a=getch();
        if (isdigit(a)){ //является ли введённый символ числом
            int b=a-'0'+1;
            printf("%d",b%10);
        } else{
            printf("%c",a);
        }
    }
    return 0;
}
