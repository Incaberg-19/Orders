#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void sum_of_squares(int a1, int b1, int a[a1][b1],int *c);
void fill(int a1, int b1, int a[a1][b1]);
int input_n(int *n, int *n2);
void output(int a1, int b1, int a[a1][b1]);
int main(){
    srand(time(NULL));
    int a=0,b=0,c=0;
    int d=input_n(&a,&b);
    if (d==0){
        printf("incorrect variable");
        return 0;
    } else{
        int z[a][b];
        fill(a,b,z);
        sum_of_squares(a,b,z,&c);
        float result;
        result=sqrt((float)c);
        printf("%f\n",result);
        output(a,b,z);
    }
}
void output(int a1, int b1, int a[a1][b1]){
    for (int i=0; i<a1; i++){
        for (int j=0; j<b1; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void fill(int a1, int b1, int a[a1][b1])
{
    for (int i=0; i<a1; ++i){
        for (int j=0; j<b1; ++j){
            a[i][j]=0;
        }
    }
    int i,j;
    for (i = 0; i<a1; i++){
        for (j=0; j<b1; j++){
            a[i][j] = rand () % 10;
        }
    }
}

int input_n(int *n, int *n2){
    char ch;
    if (scanf("%d %d%c",n,n2,&ch)!=3 || ch!='\n' || *n<0 || *n2<0){
        return 0;
    } else{
        return 1;
    }
}

void sum_of_squares(int a1, int b1, int a[a1][b1],int *c){
    for (int i=0; i<a1; i++){
        for (int j=0; j<b1; j++){
            *c+=a[i][j]*a[i][j];
        }
    }
}
//функция sum_of_squares вычисляет сумму квадратов всех элементов двумерного массива
//и сохраняет результат в переменной c.