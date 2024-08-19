#include <stdio.h>
int found_NOD_cycle(int a, int b);
int found_NOD_recursion(int a,int b);
int main(void){
    int a=0,b=0;
    while (1){
        scanf("%d %d",&a,&b);
        if (a<0 || b<0){
            printf("Не по заданию\n");
        } else{
            printf("%d\n",found_NOD_cycle(a,b));
            printf("%d\n",found_NOD_recursion(a,b));
        }
    }
    return 0;
}
int found_NOD_recursion(int a,int b){
    return (a==0 || b==0) ? 0 : a!=b ? a>b ? found_NOD_recursion(a-b,b) : found_NOD_recursion(a,b-a) : a;
    //тот же самый алгоритм евклида
    //большие числа рекурсии делать трудно
}
int found_NOD_cycle(int a, int b){ //алгоритм евклида
    if (a==0 || b==0){
        return 0;
    }
    while (a != b) { //пока одно число не равно другому цикл продолжается
        if (a > b){ 
            a = a - b;
        } else{
            b = b - a;
        }
    }
    return a;
}