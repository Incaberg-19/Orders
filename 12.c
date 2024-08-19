#include <stdio.h>
#include <string.h>
struct shop
{
    char name[50];
    char adress[50];
    int discount;
    char distribution[100];
};

void Write_instanses(struct shop *instanses, int size);
void input_contents(struct shop *instanses);
void find_most_discount(struct shop *instanses, int count_of_instanses);
void Read_instanses(struct shop *instanses, int maxSize,int *count_of_instanses);

int main(void){
    int count_of_instanses=0,size=100;
    struct shop instanses[size];
    memset(instanses,0,sizeof(instanses));
    Read_instanses(instanses,size,&count_of_instanses); //ф-ия считывания экземпляров из файла
    while(1){
        printf("Button '1' - check list\nButton '2' - add new instanses\nButton '3' - remove some instanse\nButton '4' - find by discount\nButton '5' - Exit\n");
        int key=0;
        scanf("%d",&key);
        if (key==5){
            break;
        }
        if (key==4){
            find_most_discount(instanses, count_of_instanses);
        }
        if (key==1){
            for (int i=0; i<count_of_instanses; i++){
                printf("Number of instanses - %d\nНазвание магазина - %s\nАдрес - %s\nСкидка - %d\nНа что распространяется: %s\n\n",
                i+1, instanses[i].name, instanses[i].adress,instanses[i].discount, instanses[i].distribution);
            }
        }
        //i+1 показывает номер экземпляра
        if (key==2){
            input_contents(&instanses[count_of_instanses]);
            count_of_instanses++;
        }
        if (key==3){
            printf("Button '1' - delete the last of instanse\nButton '2' - delete by number\nButton '3' - Delete all\nButton '4' - exit the menu\n");
            scanf("%d",&key);
            if (key==4) continue;
            if (key==3){
                memset(instanses,0,sizeof(instanses));
                count_of_instanses=0;
            }
            if (key==1){
                memset(&instanses[count_of_instanses-1], 0, sizeof(struct shop));
                count_of_instanses--;
            }
            if (key==2){
                printf("Enter a number - ");
                scanf("%d",&key); //number is key-1
                if (key-1<count_of_instanses){
                for (int i = key-1; i < count_of_instanses+1; i++) {
                    instanses[i] = instanses[i + 1];
                }
                if (count_of_instanses>0) count_of_instanses--;
                } else{
                    printf("The element you entered does not exist\n");
                }
            }
        }
    }
    Write_instanses(instanses,count_of_instanses);
    return 0;
}

void Read_instanses(struct shop *instanses, int maxSize, int* count_of_instances) {
   FILE *file = fopen("history_of_instanses.txt", "r");
   if (file == NULL) {
       return;
   }

   int i = 0;
   char line[256];
   while (i < maxSize && fgets(line, sizeof(line), file)) {
    if (strlen(line)==1) continue; //если строка пустая то пускаем цикл while заного
       strcpy(instanses[i].name, line);
       instanses[i].name[strcspn(instanses[i].name, "\n")] = 0;
       fgets(line, sizeof(line), file);
       strcpy(instanses[i].adress, line);
       instanses[i].adress[strcspn(instanses[i].adress, "\n")] = 0;
       fgets(line, sizeof(line), file);
       sscanf(line, "%d", &instanses[i].discount);
       fgets(line, sizeof(line), file);
       strcpy(instanses[i].distribution, line);
       instanses[i].distribution[strcspn(instanses[i].distribution, "\n")] = 0; //заменяем созданный fgets /n символом конца строки
       i++;
   }

   *count_of_instances = i;

   fclose(file);
}

void Write_instanses(struct shop *instanses, int size) {
    FILE *file = fopen("history_of_instanses.txt", "w");
    if (file == NULL) { 
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n%s\n%d\n%s\n\n",
        instanses[i].name, instanses[i].adress,instanses[i].discount, instanses[i].distribution);   
    }

    fclose(file);
}

void find_most_discount(struct shop *instanses, int count_of_instanses){
    int save_i=0,discount=0,key_for_check_instanses_exist=0;
    for (int i=0; i<count_of_instanses; i++){
        if (strstr(instanses[i].distribution,"clothes")!=0 || strstr(instanses[i].distribution,"Clothes")!=0){
            if (instanses[i].discount>discount){
                discount=instanses[i].discount;
                save_i=i;
                key_for_check_instanses_exist=1;
            }
        }
    }
    if (key_for_check_instanses_exist==0){
        printf("Instanses does not exist\n");
    } else{
        printf("Number of instanses - %d\nНазвание магазина - %s\nАдрес - %s\nСкидка - %d\nНа что распространяется: %s\n\n",
        save_i+1, instanses[save_i].name, instanses[save_i].adress,instanses[save_i].discount, instanses[save_i].distribution);
    }
}

void input_contents(struct shop *instanses){
    fflush(stdin); // это нужно для того чтобы убрать лишние \n в буффере (чтобы они не записывались к нам в массив)
    fgets(instanses->name, 50, stdin);
    instanses->name[strcspn(instanses->name, "\n")] = 0;
    fgets(instanses->adress, 50, stdin);
    instanses->adress[strcspn(instanses->adress, "\n")] = 0;
    scanf("%d",&instanses->discount);
    fflush(stdin);
    fgets(instanses->distribution, 50, stdin);
    instanses->distribution[strcspn(instanses->distribution, "\n")] = 0;
}