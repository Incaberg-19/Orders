#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int main()
{
    int key_for_first_print=0,key1=0,key2=0;
    int save_1=0,save_2=0,save_3=0; //переменные для сохранения первой тройки
    int count=0;
    char a=' ';
    while (a!=27){ //в моей системе ESCAPE имеет порядковый номер 27, тебе самой нужно будет проверить какой у тебя номер, гайд написан ниже
    //пока введённая клавиша не равна порядкову номеру 27(ESCAPE) продолжаем цикл
        if (key_for_first_print==0){
            printf("Сначала введите тройку символов,затем начните вводить последовательность символов\n");
            key_for_first_print=1;
        }
        a=getch();
        printf("%c",a);
        if (!iscntrl(a)) { //проверка на функциональную клавишу, нам же нужны только символы 
            if (save_1==0 || save_2==0 || save_3==0){
    //проверка на нули save переменных
                if (save_1==0){
                    save_1=a;
                } else if(save_2==0){
                    save_2=a;
                } else if(save_3==0){
                    save_3=a;
                    printf(" "); //пробел принтуем чтоб слева была искомая тройка, а справа строка
                }
            } else{
                if (a==save_1){
                    key1=1;
                }
                if(a==save_2 && key1==1){
                    key2=1;
                }
                if(a==save_3 && key2==1 && key1==1){
                    count++;
                    key1=0;
                    key2=0;
                } 
            }
        }
    }
    printf("\nЧастота - %d",count);
    return 0;
}