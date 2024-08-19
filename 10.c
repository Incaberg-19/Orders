#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int N, int M, int *a);
void output(int N, int M, int *a);
int* transpose(int N, int M, int *a);
int sum_of_3_diagonals(int N, int M, int *a);
void Null_of_other(int N, int M, int *a);
void fail();

int main(void){
    srand(time(NULL));
    printf("Введите кол-во строк и кол-во столбцов:\n");
    int N=0,M=0,number=0;
    scanf("%d %d",&N,&M);
    printf("Задайте число - ");
    scanf("%d",&number);
    printf("\n");
    int* array = (int *)malloc(N * M * sizeof(int));
    if (!array) fail();
    fill(N, M, array);
    output(N, M, array);
    printf("\n");
    if (number<sum_of_3_diagonals(N, M, array)){
        int* array_for_transpose = transpose(N, M, array);
        output(M, N, array_for_transpose);
        free(array_for_transpose);
    } else {
        Null_of_other(N, M, array);
        output(N, M, array);
    }
    free(array);
}

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

int sum_of_3_diagonals(int N, int M, int *a){ //сумма 3 диагоналей
    int sum=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == j || i == j-1 || i == j+1) {
                sum += a[i * M + j];
            }
        }
    }
    return sum;
}

void Null_of_other(int N, int M, int *a){ //зануление остальных (всех кроме 3 диагоналей) элементов
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            if (i != j && i != j-1 && i != j+1) {
                a[i * M + j] = 0;
            }
        }
    }
}

int* transpose(int N, int M, int *a){
    int* temp = (int*)malloc(N * M * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp[j * N + i] = a[i * M + j];
        }
    }
    return temp;
}

void output(int N, int M, int *a){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", a[i * M + j]);
        }
        printf("\n");
    }
}
void fill(int N, int M, int *a){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            a[i * M + j] = rand () % 10; //заполнение "случайными" числами в промежутке [0,9]
        }
    }
}
