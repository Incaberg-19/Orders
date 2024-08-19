#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int N,int M, int **a);
void output(int N,int M, int **a);
int** transpose(int N,int M, int **a);
int sum_of_3_diagonals(int N,int M, int **a);
void Null_of_other(int N,int M, int **a);

int main(void){
    srand(time(NULL));
    printf("Введите кол-во строк и кол-во столбцов:\n");
    int N=0,M=0,number=0;
    scanf("%d %d",&N,&M);
    printf("Задайте число - ");
    scanf("%d",&number);
    printf("\n");
    int** array = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        array[i] = (int*)malloc(M * sizeof(int));
    }
    fill(N,M,array);
    output(N,M,array);
    printf("\n");
    if (number<sum_of_3_diagonals(N,M,array)){
    int** array_for_transpose = transpose(N,M,array);
    output(M,N,array_for_transpose);
    //освобождение памяти транспонированной матрицы
    for (int i = 0; i < M; i++) {
      free(array_for_transpose[i]);
    }
    free(array_for_transpose);
    } else {
        Null_of_other(N,M,array);
        output(N,M,array);
    }
    //освобождаем память выделенную на изначальную матрицу
    for (int i = 0; i < N; i++) {
      free(array[i]);
    }
    free(array);
}

int sum_of_3_diagonals(int N,int M, int **a){
    int sum=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == j || i == j-1 || i == j+1) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

void Null_of_other(int N,int M, int **a){
    // обнуление элементов матрицы кроме главной диагонали и двух соседних
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            if (i != j && i != j-1 && i != j+1) {
                a[i][j] = 0;
            }
        }
    }
}

int** transpose(int N,int M, int **a){
    int** temp = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++) {
        temp[i] = (int*)malloc(N * sizeof(int));
    }
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            temp[i][j]=0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[j][i]=a[i][j];
        }
    }
    return temp;
}

void output(int N,int M, int **a){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void fill(int N,int M, int **a){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j]=0;
        }
    }
    //заполняем массив нулями для того чтобы в них случайно не оказалось мусорных значений
    for (int i = 0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j] = rand () % 10; //заполнение "случайными" числами в промежутке [0,9]
        }
    }
}