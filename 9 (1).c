#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void processing(char *a);

int main(){
    char array[100]={0};
    fgets(array,100,stdin);
    processing(array);
    return 0;
}
void processing(char *a){
    size_t N = strlen(a)+1;
    char array_for_comfortable_sort[100][100]={{0},{0}};
    size_t j=0,k=0;
    for (size_t i=0; i<N; i++){
        if ((a[i]!='\0') && (a[i]!=' ')){ //если не встречается пробел или конец строки
            array_for_comfortable_sort[k][j++]=a[i]; //мы записываем в k элемент слово
        } else{
            array_for_comfortable_sort[k][j]='\0'; //если встретилось что-то из этого в конец строки ставим конец строки - \0
            j=0; // обнуляем длину слова для последующих записей
            k++; //увеличиваем k чтобы записать новое слово уже в другую ячейку
        }
    }
    array_for_comfortable_sort[k-1][strlen(array_for_comfortable_sort[k-1])-1]='\0';
    //в этот элемент видимо что-то лишнее записывается, может  ещё один '\0', и так получается что если мы его не убираем
    //то проверка на уникальные слова не работает
    int check=0;
    for (size_t i=0; i<k; i++){
        for (size_t j=0; j<k; j++){
            if (strcmp(array_for_comfortable_sort[i],array_for_comfortable_sort[j])==0 && i!=j){ //проверка на совпадения
                check=1; 
            }
        }
        if (check==0){
            printf("%s ",array_for_comfortable_sort[i]);
        } else{
            check=0;
        }
    }
}