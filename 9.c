#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//мы суммируем числа, а не цифры
int main(){
    char array[100]={0};
    fgets(array,100,stdin);
    long long int sum=0,count_for_temp=0;
    char temp[100]={0};
    for (size_t i=0; i<strlen(array); i++){
        if (array[i]>=48 && array[i]<=57){ //если итый элемент находится в промежутке [0,9] (48-57 это порядковые номера цифр)
            temp[count_for_temp]=array[i]; //добавляем цифру в массив
            count_for_temp++;
            if (!(array[i+1]>=48 && array[i+1]<=57)){ //если след.символ цифрой не является и работаем с теми цифрами которые записали
                sum+=strtol(temp,NULL,10); //превращение чар массива в числа и сразу прибавления этого числа к сумме
                memset(temp,0,100); //обнуление временного массива
                count_for_temp=0; //обнуление счётчика временного массива
            }
        }
    }
    // printf("\n%s\n",array);
    printf("%lld\n",sum);
    return 0;
}