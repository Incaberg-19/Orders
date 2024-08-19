#include <stdio.h>
#include <string.h>

struct intercity_buses
{
    int bus_number; //номер автобуса
    char destinations[100]; //пункты назначения
    char departure_time[100]; //время отправления
    char arrival_time[100]; //время прибытия
};

void Write_instanses(struct intercity_buses *instanses, int size);
void input_contents(struct intercity_buses *instanses);
void find_bus_by_town(struct intercity_buses *instanses, int count_of_instanses,char *found);
void output_instanses(struct intercity_buses *instanses);
void Read_instanses(struct intercity_buses *instanses, int maxSize,int *count_of_instanses);

int main(void){
    int count_of_instanses=0,size=100;
    struct intercity_buses instanses[size];
    memset(instanses,0,sizeof(instanses));
    Read_instanses(instanses,size,&count_of_instanses); //ф-ия считывания экземпляров из файла
    while(1){
        printf("1 - Просмотреть список\n2 - Добавить новый автобус\n3 - Удалить автобус\n4 - Получить информацию о следующих в город автобусах\n5 - Выйти\n");
        int key=0;
        scanf("%d",&key);
        if (key==5){
            break;
        }
        if (key==4){
            printf("Введите название города\n");
            char found[100]={0};
            fflush(stdin);
            fgets(found,100,stdin);
            found[strlen(found)-1]='\0'; //убираем вставленный fgets'ом \n
            find_bus_by_town(instanses,count_of_instanses,found);
        }
        if (key==1){
            for (int i=0; i<count_of_instanses; i++){
                output_instanses(&instanses[i]);
            }
        }
        if (key==2){
            input_contents(&instanses[count_of_instanses]);
            count_of_instanses++;
        }
        if (key==3){
            printf("1 - Удалить последний добавленный автобус\n2 - Удалить автобус по его номеру\n3 - Удалить всё\n4 - Выйти из меню\n");
            scanf("%d",&key);
            if (key==4) continue;
            if (key==3){
                memset(instanses,0,sizeof(instanses));
                count_of_instanses=0;
            }
            if (key==1){
                memset(&instanses[count_of_instanses-1], 0, sizeof(struct intercity_buses));
                count_of_instanses--;
            }
            if (key==2){
                printf("Введине номер автобуса - ");
                scanf("%d",&key); 
                int find_or_not=0;
                for (int i=0; i<count_of_instanses; i++){
                    if (instanses[i].bus_number==key || find_or_not==1){
                        instanses[i] = instanses[i + 1];
                        find_or_not=1;
                    }
                }
                if (find_or_not==0){
                    printf("Автобус не найден\n");
                } else{
                    printf("Автобус успешно удалён!\n");
                    if (count_of_instanses>0) count_of_instanses--;
                }
            }
        }
    }
    Write_instanses(instanses,count_of_instanses);
    return 0;
}

void output_instanses(struct intercity_buses *instanses){
    printf("Номер автобуса - %d\nПункт прибытия - %s\nВремя отправления - %s\nВремя прибытия - %s\n\n",
    instanses->bus_number, instanses->destinations, instanses->departure_time, instanses->arrival_time);
}

void Read_instanses(struct intercity_buses *instanses, int maxSize,int *count_of_instanses) {
   FILE *file = fopen("history_of_instanses.txt", "r");
   if (file == NULL) {
       return;
   }

   int i = 0;
   char line[256]={0};
   while (i < maxSize && fgets(line, sizeof(line), file)) {
    if (strlen(line)==1) continue; //если строка пустая то пускаем цикл while заного
        sscanf(line, "%d", &instanses[i].bus_number);

        fgets(line, sizeof(line), file);
        strcpy(instanses[i].destinations, line);
        instanses[i].destinations[strcspn(instanses[i].destinations, "\n")] = 0;

        fgets(line, sizeof(line), file);
        strcpy(instanses[i].departure_time, line);
        instanses[i].departure_time[strcspn(instanses[i].departure_time, "\n")] = 0;

        fgets(line, sizeof(line), file);
        strcpy(instanses[i].arrival_time, line);
        instanses[i].arrival_time[strcspn(instanses[i].arrival_time, "\n")] = 0; //заменяем созданный fgets /n символом конца строки
        i++;
   }
   *count_of_instanses = i;

   fclose(file);
}

void Write_instanses(struct intercity_buses *instanses, int size){
    FILE *file = fopen("history_of_instanses.txt", "w");
    if (file == NULL) { 
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n%s\n%s\n%s\n\n",
        instanses[i].bus_number, instanses[i].destinations, instanses[i].departure_time, instanses[i].arrival_time);   
    }

    fclose(file);
}

void find_bus_by_town(struct intercity_buses *instanses, int count_of_instanses,char *found){
    int find_or_not=0;
    for (int i=0; i<count_of_instanses; i++){
        if (strstr(instanses[i].destinations,found)!=0){
            output_instanses(&instanses[i]);
            find_or_not=1;
        }
    }
    if (find_or_not==0){
        printf("Такого города не найдено\n");
    }
}

void input_contents(struct intercity_buses *instanses){
    scanf("%d",&instanses->bus_number);
    fflush(stdin); //это нужно для того чтобы убрать лишние \n в буффере (чтобы они не записывались к нам в массив)
    fgets(instanses->destinations, 100, stdin);
    instanses->destinations[strcspn(instanses->destinations, "\n")] = 0;

    fgets(instanses->departure_time, 100, stdin);
    instanses->departure_time[strcspn(instanses->departure_time, "\n")] = 0;

    fgets(instanses->arrival_time, 100, stdin);
    instanses->arrival_time[strcspn(instanses->arrival_time, "\n")] = 0;
}