#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void fill(int N,int M, double **a);
void output(int N,int M, double **a);
int max_element_by_module(int N,int M, double **a);
void division(int N,int M, double **a,int max_value_by_module);

int main(void){
    srand(time(NULL));
    printf("Введите кол-во строк и кол-во столбцов:\n");
    int N=0,M=0;
    scanf("%d %d",&N,&M);
    printf("\n");
    double** array = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        array[i] = (double*)malloc(M * sizeof(double));
    }
    fill(N,M,array);
    output(N,M,array);
    printf("\n");
    printf("%d\n\n",max_element_by_module(N,M,array));
    division(N,M,array,max_element_by_module(N,M,array));
    output(N,M,array);
    //освобождаем память выделенную на изначальную матрицу
    for (int i = 0; i < N; i++) {
      free(array[i]);
    }
    free(array);
}

void division(int N,int M, double **a,int max_value_by_module){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == j || i == j-1 || i == j+1 || (i + j == M - 1) || (i + j == M - 2) || (i + j == M)) {
                a[i][j] = ((a[i][j])/max_value_by_module);
            }
        }
    }
}

int max_element_by_module(int N,int M, double **a){
    int max_by_module=fabs(a[0][0]);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (abs(a[i][j])>max_by_module){
                max_by_module=fabs(a[i][j]);
            }
        }
    }
    if (N>0 && M>0) return max_by_module;
}


void output(int N,int M, double **a){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            printf("%0.3lf ",a[i][j]);
        }
        printf("\n");
    }
}

void fill(int N,int M, double **a){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j]=0;
        }
    }
    //заполняем массив нулями для того чтобы в них случайно не оказалось мусорных значений
    for (int i = 0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j] = rand () % 101 - 50; //заполнение "случайными" числами в промежутке [-50,50]
        }
    }
}