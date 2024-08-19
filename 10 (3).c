#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void sum_of_squares(int a1, int b1, int **a,int *c);
void fill(int a1, int b1, int **a);
int input_n(int *n, int *n2);
void output(int a1, int b1, int **a);
void FREEDOM(int **a, int n, int m);
int main(){
    srand(time(NULL));
    int a=0,b=0,c=0;
    int d=input_n(&a,&b); //a-кол-во строчек, b-кол-во элементов в строчке
    if (d==0){
        printf("incorrect variable");
        return 0;
    } else{
        int **pointer_array=(int **)malloc(a*sizeof(int*));
        for (int i=0; i<a; i++){
            pointer_array[i]=(int *)malloc(b*sizeof(int));
        }
        fill(a,b,pointer_array);
        sum_of_squares(a,b,pointer_array,&c);
        float result;
        result=sqrt((float)c);
        printf("%f\n",result);
        output(a,b,pointer_array);
        FREEDOM(pointer_array,a,b);
    }
}
void FREEDOM(int **a, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = i * m + j + 1;
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}
void output(int a1, int b1, int **a){
    for (int i=0; i<a1; i++){
        for (int j=0; j<b1; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void fill(int a1, int b1, int **a)
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

void sum_of_squares(int a1, int b1, int **a,int *c){
    for (int i=0; i<a1; i++){
        for (int j=0; j<b1; j++){
            *c+=a[i][j]*a[i][j];
        }
    }
}

//функция sum_of_squares вычисляет сумму квадратов всех элементов двумерного массива
//и сохраняет результат в переменной c.