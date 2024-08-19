#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cafe {
   char nameofdish[32]; //surname
   char category[32]; //name
   char caloriecontent[32]; //birthdate
   char grams[64]; //address
   char price[16]; //phone
} cafs[100]; //friends

int dish_count = 0;

void print_dishes() {
   for (int i = 0; i < dish_count; i++) 
   {
      printf("%s %s %s %s %s\n", cafs[i].nameofdish, cafs[i].category, cafs[i].caloriecontent, cafs[i].grams, cafs[i].price);
   }
}

void add_dish() 
{
   printf("Введите название блюда: ");
   scanf("%s", cafs[dish_count].nameofdish);
   printf("Введите категорию (напитки, первые блюда и т.д.): ");
   scanf("%s", cafs[dish_count].category);
   printf("Введите калорийность: ");
   scanf("%s", cafs[dish_count].caloriecontent);
   printf("Введите граммовку: ");
   scanf("%s", cafs[dish_count].grams);
   printf("Введите цену: ");
   scanf("%s", cafs[dish_count].price);
   dish_count++;
}

void delete_dish() 
{
   int index;
   printf("Введите название блюда для удаления: ");
   scanf("%d", &index);
   if (index < 0 || index >= dish_count) 
   {
      printf("Invalid index\n");
      return;
   }
   for (int i = index; i < dish_count - 1; i++) 
   {
   cafs[i] = cafs[i + 1];
   }
   dish_count--;
}

void save_cafe_to_file() 
{
   FILE *f = fopen("cafe.txt", "w");
   for (int i = 0; i < dish_count; i++) 
   {
   fprintf(f, "%s %s %s %s %s\n", cafs[i].nameofdish, cafs[i].category, cafs[i].caloriecontent, cafs[i].grams, cafs[i].price);
   }
   fclose(f);
}

void load_cafe_from_file() 
{
   FILE *f = fopen("cafe.txt", "r");
   dish_count = 0;
   while (fscanf(f, "%s %s %s %s %s\n", cafs[dish_count].nameofdish, cafs[dish_count].category, cafs[dish_count].caloriecontent, cafs[dish_count].grams, cafs[dish_count].price) != EOF) 
   {
   dish_count++;
   }
   fclose(f);
}

void get_dish_by_category() 
{
   char cat[32] = "Второе";
   for (int i = 0; i < dish_count; i++){
      if (strcmp(cafs[i].category, cat) == 0)
      {
         printf("%s %s %s %s %s\n", cafs[i].nameofdish, cafs[i].category, cafs[i].caloriecontent, cafs[i].grams, cafs[i].price);
      }
   }
}

int main() 
{
   load_cafe_from_file();
   int choice;
   do 
   {
      printf("1. Вывести блюда\n");
      printf("2. Добавить блюда\n");
      printf("3. Удалисть блюда\n");
      printf("4. Вторые блюда\n");
      printf("5. Выход\n");
      printf("Выбор: ");
      scanf("%d", &choice);
      switch (choice) 
      {
         case 1:
         print_dishes();
         break;
         case 2:
         add_dish();
         break;
         case 3:
         delete_dish();
         break;
         case 4:
         get_dish_by_category();
         break;
      }
   } while (choice != 5);
   save_cafe_to_file();
return 0;
}
