#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t count_of_unic_symvols(char *a);
void processing(char *a);
int main() {
   char str[100]={0};
   fgets(str,100,stdin);
   str[strcspn(str, "\n")] = 0;
   processing(str);
   return 0;
}

//Если внутренний цикл завершен без прерывания
//(то есть все символы были проверены и ни один из них не совпадал с текущим символом),
//то увеличивается значение unic
size_t count_of_unic_symvols(char *a){
    size_t unic=0,i=0,j=0;
    for(i=0; i<strlen(a); i++) {
        for(j=0; j<strlen(a); j++) {
            if (i!=j && a[i]==a[j]) break;
        }
        if (j==strlen(a)) unic++;
    }
    return unic;
}

void processing(char *a){
    size_t N = strlen(a)+1;
    char array_for_comfortable_sort[100][100]={{0},{0}};
    size_t j=0,k=0; //k отвечает за кол-во слов
    for (size_t i=0; i<N; i++){
        if ((a[i]!='\0') && (a[i]!=' ')){ //если не встречается пробел или конец строки
            array_for_comfortable_sort[k][j++]=a[i]; //мы записываем в k элемент слово
        } else{
            array_for_comfortable_sort[k][j]='\0'; //если встретилось что-то из этого в конец строки ставим конец строки - \0
            j=0; // обнуляем длину слова для последующих записей
            k++; //увеличиваем k чтобы записать новое слово уже в другую ячейку
        }
    }
    array_for_comfortable_sort[k-1][strlen(array_for_comfortable_sort[k])-1]='\0';
    //в этот элемент видимо что-то лишнее записывается, может  ещё один '\0', и так получается что если мы его не убираем
    //то проверка не работает
    size_t array_sum_of_frequency[100]={0};
    size_t max_of_sum_of_frequency=0;
    for (size_t i=0; i<k; i++){
        if (max_of_sum_of_frequency<(strlen(array_for_comfortable_sort[i])-count_of_unic_symvols(array_for_comfortable_sort[i]))){
            max_of_sum_of_frequency=(strlen(array_for_comfortable_sort[i])-count_of_unic_symvols(array_for_comfortable_sort[i]));
        }
    }
    for (size_t i=0; i<k; i++){
        if (max_of_sum_of_frequency!=(strlen(array_for_comfortable_sort[i])-count_of_unic_symvols(array_for_comfortable_sort[i]))){
            printf("%s ",array_for_comfortable_sort[i]);
        }
    }
}