#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail();
void input_sizes_of_array(int *N,int *M);
void initializing_2D_array(int ***array,int N,int M);
void free_2D_array(int **array,int N);
void fill_2D_array(int N,int M, int **array);
void output_2D_array(int N,int M, int **array);
void bubble_sort_with_conditions(int **array,int N,int M);

int main(void){
    int N,M; // N-Колличество строчек, M - колличество элементов в строке
    input_sizes_of_array(&N,&M);
    int **array=NULL;
    initializing_2D_array(&array,N,M);
    fill_2D_array(N,M,array);
    output_2D_array(N,M,array);
    bubble_sort_with_conditions(array,N,M);
    printf("The next one\n");
    output_2D_array(N,M,array);
    free_2D_array(array,N);
    return 0;
}

void bubble_sort_with_conditions(int **array,int N,int M){
    int *temp=calloc(M,sizeof(int));
    for (int i=0; i<N-1; i++){
        for (int j = N-1; j>i; j--){
            if (array[j-1][0]<array[j][0]){
                for (int k=0; k<M; k++){
                    temp[k]=array[j-1][k];
                    array[j-1][k]=array[j][k];
                }
                for (int k=0; k<M; k++){
                    array[j][k]=temp[k];
                }
            }
        }
    }
}

void output_2D_array(int N,int M, int **array){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void fill_2D_array(int N,int M, int **array){
    for (int i = 0; i<N; i++){
        for (int j=0; j<M; j++){
            array[i][j] = rand () % 101 - 50; //заполнение "случайными" числами в промежутке [-50,50]
        }
    }
}

void free_2D_array(int **array,int N){
    for (int i = 0; i < N; i++)
        free(array[i]);
    free(array);
}

void input_sizes_of_array(int *N,int *M){
    scanf("%d%d",N,M);
}

void initializing_2D_array(int ***array,int N,int M){
    *array = (int **)calloc(N,sizeof(int *));
    if (!*array) 
        fail();
    for (int i = 0; i < N; i++)
    {
        (*array)[i] = (int *)calloc(M,sizeof(int));
        if (!(*array)[i])
            fail();
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            (*array)[i][j] = i * M + j +  1;
}

void fail()
{
    printf("Memory allocation failure!\n");
    exit(1);
}