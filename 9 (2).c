#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processing(char *a);
size_t found_most_popular_len(size_t k,size_t j,char a[k][j]);

int main(){
    char array[100]={0};
    fgets(array,100,stdin);
    processing(array);
    return 0;
}

size_t found_most_popular_len(size_t k,size_t j,char a[k][j]){
    int count_of_one_word_was=-1,save_i=-1;
    for (int i=0; i<k; i++){
        char temp[strlen(a[i])];
        strcpy(temp,a[i]);
        int count_of_one_word=0;
        for (int h=i+1; h<k; h++){
            if (strlen(temp)==strlen(a[h])){ //если длина i элемента массива равна длине h элемента
                count_of_one_word++;  //массива то прибавляем счётчик
            }
        }
        if ((count_of_one_word_was<count_of_one_word) && (count_of_one_word!=0)){
            count_of_one_word_was=count_of_one_word;
            save_i=i; //запоминаем индекс элемента который чаще всего встречается 
        }
    }
    return (strlen(a[save_i]));
}

void processing(char *a){
    size_t N = strlen(a)+1;
    char array_for_comfortable_sort[100][100]={{0},{0}};
    size_t j=0,k=0; // k - кол-во слов
    for (size_t i=0; i<N; i++){
        if ((a[i]!='\0') && (a[i]!=' ')){ //если не встречается пробел или конец строки
            array_for_comfortable_sort[k][j++]=a[i]; //мы записываем в k элемент слово
        } else{
            array_for_comfortable_sort[k][j]='\0'; //если встретилось что-то из этого в конец строки ставим конец строки - \0
            j=0; // обнуляем длину слова для последующих записей
            k++; //увеличиваем k чтобы записать новое слово уже в другую ячейку
        }
    }
    array_for_comfortable_sort[k-1][strlen(array_for_comfortable_sort[k-1])-1]='\0'; //убираем \n созданный fgets
    size_t most_popular_len = found_most_popular_len(k,100,array_for_comfortable_sort);
    for (size_t i=0; i<k; i++){
        if (strlen(array_for_comfortable_sort[i])!=most_popular_len){
            printf("%s ",array_for_comfortable_sort[i]);
        }
    }
}