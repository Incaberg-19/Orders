#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Заполняем массив и выводим его
void fill_array(int n, int array[n]){
    for (int i = 0; i < n; i++){
        array[i] = rand () % 10;
        printf("%d ", array[i]);
    }
    printf("\n");
}


//Проверяем есть ли совпадение элемента/ов в массиве A с индексом ind_a в массиве B 
//Возвращаем значение 1 если есть совпадение/я илл 0 если совпадений нет.
int check_array(int *a, int ind_a, int *b, int b_size){
    int check = 0;
    for (int i = 0; i < b_size; i++){
        if (a[ind_a] == b[i]){
            check = 1;
          break;
        }
    }
    return (check);
}


//Проверяем массив C на наличение уникальных элемента/ов, дабы избежать дубликации. 
void matches_array(int *a, int a_size, int *b, int b_size, int *c, int c_size){
    int k = 0;
    for (int i = 0; i < a_size; i++){
        if ((check_array(a, i, b, b_size) == 1) && (check_array(a, i, c, c_size) == 0)){
            c[k]=a[i];
          k++;
        }
    }
}

int main()
{
    srand(time(NULL));
    int n, m, i = 0;
    printf("Длина массива A -> ");
    scanf("%d", &n);
    printf("Длина массива B -> ");
    scanf("%d", &m);
    int k = n < m? n : m; //Т.к массив может состоят хоть из миллиарда чисел, но уникальных чисел будет кратно меньше,
    int a[n], b[m], c[k]; //то проводим проверку, какой из массивов меньше, и задаем такую длину массиву C.
    printf("Массив А:\n");
    fill_array(n, a);
    printf("Массив B:\n");
    fill_array(m, b);
    for (int i = 0; i < k; i++) // Заполняем пустой массив каким-либо числом которое не может быть в диапазоне генерации,
        c[i] = -99999999;
    matches_array(a, n, b, m, c, k);
    printf("Массив C:\n");
    while (c[i] != -99999999){  //и после его заполнения в функции matches_array убираем это число.
        printf("%d ", c[i]);
        i++;
    }
    return 0;
}
