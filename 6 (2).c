#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int N, int a[N]);
int input_n(int *n);
void output(int N, int a[N]);

void make_exclusive_array(int N, int a[N],int b[N],int result_array[N*2],int *count_of_result_array);

int main(void){
    srand(time(NULL));
    int N=0;
    int check=input_n(&N);
    if (check==0){
        printf("incorrect variable");
    } else{
        int A[N];
        int B[N];
        int count_of_result_array=0;
        int result_array[N*2];
        fill(N,A);
        output(N,A);
        printf("\n");
        fill(N,B);
        output(N,B);
        printf("\n");
        make_exclusive_array(N,A,B,result_array,&count_of_result_array);
        printf("Exc Array: ");
        for (int i=0; i<count_of_result_array; i++){
            printf("%d ",result_array[i]);
        }
    }
    return 0;
}

void make_exclusive_array(int N, int a[N],int b[N],int result_array[N*2],int *count_of_result_array){
    int count=0;
    for (int i=0; i<N; i++){
        int count_of_one_number_first=0,count_of_one_number_twist=0;
        for (int h=0; h<N; h++){
            if (a[i]==b[h] || (a[i]==a[h] && i!=h)){ 
                count_of_one_number_first=1;  
            }
            if (b[i]==a[h] || (b[i]==b[h] && i!=h)){ 
                count_of_one_number_twist=1;  
            }
        }
        if (count_of_one_number_first!=1){
            result_array[count]=a[i];
            count++;
            count_of_one_number_first=0;
        } else{
            count_of_one_number_first=0;
        }

        if (count_of_one_number_twist!=1){
            result_array[count]=b[i];
            count++;
            count_of_one_number_twist=0;
        } else{
            count_of_one_number_twist=0;
        }
    }
    *count_of_result_array=count;
}

int input_n(int *n){
    char ch;
    if (scanf("%d%c",n,&ch)!=2 || ch!='\n' || *n<=0){
        return 0;
    } else{
        return 1;
    }
}

void fill(int N, int a[N]){
    for (int i=0; i<N; i++){
        a[i]=0;
    }
    //заполняем массив нулями для того чтобы в них случайно не оказалось мусорных значений
    for (int i = 0; i<N; i++){
        a[i] = rand () % 40 - 19; //заполнение "случайными" числами в промежутке [-19,20]
    }
}

void output(int N, int a[N]){
    printf("Array: ");
    for (int i=0; i<N; i++){
        printf("%d ",a[i]);
    }
}