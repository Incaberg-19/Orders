#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int input_n(int *n);
void fill(int N, int a[N][N]);
void output(int N, int a[N][N]);
void make_symmetric(int N, int a[N][N]);

int main(void){
    srand(time(NULL));
    //матрица может быть симметричной только если она квадратная
    int N=0;
    int check=input_n(&N);
    if (check==0){
        printf("incorrect variable");
        return 0;
    } else{
        int array[N][N];
        fill(N,array);
        // output(N,array);
        // printf("\n\n");
        make_symmetric(N,array);
        output(N,array);
    }
}

void make_symmetric(int N, int a[N][N]) {
    int sum1 = 0, sum2 = 0;
    // Считаем суммы двух треугольников
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < j){
                sum1 += a[i][j];
            } else if (i > j){
                sum2 += a[i][j];
            }
        }
    }

    // Отражаем тот треугольник, сумма которого меньше
    if (sum1 > sum2) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                a[i][j] = a[j][i];
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                a[i][j] = a[j][i];
            }
        }
    }
}

void output(int N, int a[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void fill(int N, int a[N][N]){
    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            a[i][j]=0;
        }
    }
    //заполняем массив нулями для того чтобы в них случайно не оказалось мусорных значений
    for (int i = 0; i<N; i++){
        for (int j=0; j<N; j++){
            a[i][j] = rand () % 10; //заполнение "случайными" числами в промежутке [0,9]
        }
    }
}

int input_n(int *n){
    char ch;
    if (scanf("%d%c",n,&ch)!=2 || ch!='\n' || *n<0){
        return 0;
    } else{
        return 1;
    }
}