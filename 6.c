#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int N, int a[N]);
int input_n(int *n);
void output(int N, int a[N]);
void reverse_array(int *a, int n, int iskomoe);


int main(void){
    srand(time(NULL));
    int N=0;
    printf("Enter size of array - ");
    scanf("%d",&N);
    int iskomoe=0;
    printf("Enter iskomoe - ");
    scanf("%d",&iskomoe);
    int array[N];
    fill(N,array);
    output(N,array);
    printf("\n");
    reverse_array(array,N,iskomoe);
    output(N,array);
}


void reverse_array(int *a, int n, int iskomoe){
    int temp_array[n];
    int key_for_iskomoe=0,save_i_iskomoe=0,k=n-1;
    for (int i=0; i<n; i++){ //тут заполняем нулями чтоб мусорных значений в массиве не было
        temp_array[i]=0;
        if (a[i]==iskomoe && key_for_iskomoe==0){
            key_for_iskomoe=1; //делаем ключ чтоб если след.искомые нашлись программа их не учитывала
            save_i_iskomoe=i; //сохраняем позицию первого вхождения искомого если таковое есть
        }
    }
    for (int i=0; i<n; i++){ //тут переворачиваем массив
        temp_array[k--]=a[i];
    }
    if (key_for_iskomoe==1) temp_array[save_i_iskomoe]=a[save_i_iskomoe]; //тут вставляем наше искомое в темп массив
    for (int i=0; i<n; i++){ //тут заменяем наш основной массив на изменённый
        a[i]=temp_array[i];
    }
}


void fill(int N, int a[N]){
    for (int i=0; i<N; ++i){
        a[i]=0;
    }
    //заполняем массив нулями для того чтобы в них случайно не оказалось мусорных значений
    for (int i = 0; i<N; i++){
        a[i] = rand () % 101 - 50; //заполнение "случайными" числами в промежутке [-50,50]
    }
}

void output(int N, int a[N]){
    printf("Array: ");
    for (int i=0; i<N; i++){
        printf("%d ",a[i]);
    }
}