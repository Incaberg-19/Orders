#include <stdio.h>
#include <string.h>
double with_cycle(int num);
double with_rec(int num, size_t digits);
int main()
{
    int b=0, n=0;
    char ch;
    scanf("%d",&b);
    if (b<10 && b>=0){
        printf("A digit is submitted, not a number");
        return 0;
    }
    if (b<0){
        printf("A number or digit is negative");
        return 0;
    }
    char str[100]={0};
    sprintf(str, "%d", b); // Преобразование числа в строку
    printf("With cycle - %lf\n",with_cycle(b));
    printf("With rec - %lf\n",with_rec(b,strlen(str))/strlen(str));
    return 0;
}
double with_cycle(int num) {
    char str[100]={0};
    sprintf(str, "%d", num); // Преобразование числа в строку

    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += str[i] - '0'; // Преобразование символа в число и добавление к сумме
    }

    double average = (double)sum / strlen(str); // Вычисление среднего арифметического

    return average;
}

//этой функцией мы получаем сумму цифр числа
double with_rec(int num, size_t digits) { //нам число, digits - кол-во цифр
  if (digits == 0) {
      return 0;
  }
  double lastDigit = num % 10; // Получение последней цифры числа
  return lastDigit + with_rec(num / 10, digits - 1); // Рекурсивный вызов функции
}