#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
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
//DEBIAN 6 комп в аудитории (в углу у окна)
int main()
{
    char a;
    int check1=0,check2=0,check3=0,check4=0;
    while(1){
        a = mygetch();
        //кнопка DELETE на этом компе(на других могут быть другие коды) имеет 4!!! порядковых номера - 27,91,51,126
        //ниже мы их проверяем и если 
        if (a==27){
            check1=1;
        } else if (check1==1 && a==91){
            check2=1;
        } else if (check2==1 && a==51){
            check3=1;
        } else if (check3==1 && a==126){
            break;
        } else{
            check1=0;
            check2=0;
            check3=0;
            check4=0;
        }
        
        if (!iscntrl(a)){ //проверка на функциональную клавишу
            printf("%c",a); //если клавиша не функциональная выводим символ
        } else{
            printf("%d",a); //если клавиша функциональная выводим её код
        }
    }
    return 0;
}