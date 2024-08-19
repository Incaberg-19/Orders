#include <stdio.h>
#include <string.h>
struct hotel
{
    char name[50];
    double stars;
    char adress[50];
    char phone[50];
    int default_rooms;
    int luxe_rooms;
    int free_rooms;
};

void Write_instanses(struct hotel *instanses, int size);
void input_contents(struct hotel *instanses);
void find_best_instanse_by_stars_and_free_rooms(struct hotel *instanses, int count_of_instanses);
void Read_instanses(struct hotel *instanses, int maxSize,int *count_of_instanses);

int main(void){
    int count_of_instanses=0,size=100;
    struct hotel instanses[size];
    memset(instanses,0,sizeof(instanses));
    Read_instanses(instanses,size,&count_of_instanses); //ф-ия считывания экземпляров из файла
    while(1){
        printf("Button '1' - check list\nButton '2' - add new instanses\nButton '3' - remove some instanse\nButton '4' - find best hotel\nButton '5' - Exit\n");
        int key=0;
        scanf("%d",&key);
        if (key==5){
            break;
        }
        if (key==4){
            find_best_instanse_by_stars_and_free_rooms(instanses, count_of_instanses);
        }
        if (key==1){
            for (int i=0; i<count_of_instanses; i++){
                printf("Number of instanse-%d\nName - %s\nStars-%0.1lf\nAddress - %s\nPhone - %s\nNumber of rooms - %d\nNumber of luxe rooms - %d\nNumber of free rooms - %d\n\n",
                i+1,instanses[i].name,instanses[i].stars, instanses[i].adress, instanses[i].phone, instanses[i].default_rooms, instanses[i].luxe_rooms, instanses[i].free_rooms);
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
                memset(&instanses[count_of_instanses-1], 0, sizeof(struct hotel));
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

void Read_instanses(struct hotel *instanses, int maxSize, int* count_of_instances) {
    FILE *file = fopen("history_of_instanses.txt", "r");
    if (file == NULL) {
        return;
    }
    *count_of_instances=1;
    int i = 0;
   char line[256]; //сюда записывается полученная строка с помощью fgets
    while (i < maxSize && fgets(line, sizeof(line), file)) {
    if (strlen(line)==1) continue; //если строка пустая то возвращаемся в начало while
        strcpy(instanses[i].name, line);
        instanses[i].name[strcspn(instanses[i].name, "\n")] = 0;
        fgets(line, sizeof(line), file);
        sscanf(line, "%lf", &instanses[i].stars);
        fgets(line, sizeof(line), file);
        strcpy(instanses[i].adress, line);
        instanses[i].adress[strcspn(instanses[i].adress, "\n")] = 0;
        fgets(line, sizeof(line), file);
        strcpy(instanses[i].phone, line);
        instanses[i].phone[strcspn(instanses[i].phone, "\n")] = 0; //заменяем созданный fgets /n символом конца строки
        fgets(line, sizeof(line), file);
        sscanf(line, "%d", &instanses[i].default_rooms);
        fgets(line, sizeof(line), file);
        sscanf(line, "%d", &instanses[i].luxe_rooms);
        fgets(line, sizeof(line), file);
        sscanf(line, "%d", &instanses[i].free_rooms);
        i++;
   }

    *count_of_instances = i;

    fclose(file);
}

void Write_instanses(struct hotel *instanses, int size) {
    FILE *file = fopen("history_of_instanses.txt", "w");
    if (file == NULL) { 
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n%lf\n%s\n%s\n%d\n%d\n%d\n\n",
        instanses[i].name, instanses[i].stars, instanses[i].adress, instanses[i].phone,
        instanses[i].default_rooms,instanses[i].luxe_rooms,instanses[i].free_rooms);   
    }

    fclose(file);
}

void find_best_instanse_by_stars_and_free_rooms(struct hotel *instanses, int count_of_instanses){
    int save_i=0,free_rooms=0,key_for_check_instanses_exist=0;
    double stars=0;
    for (int i=0; i<count_of_instanses; i++){
        if (instanses[i].stars>stars){
            stars=instanses[i].stars;
            save_i=i;
            free_rooms=instanses[i].free_rooms;
            key_for_check_instanses_exist=1;
        } else if(instanses[i].stars==stars){
            if (instanses[i].free_rooms>free_rooms){
                save_i=i;
            }
        }
    }
    if (key_for_check_instanses_exist==0){
        printf("Instanses does not exist\n");
    } else{
        printf("Number of instanse-%d\nName - %s\nStars-%0.1lf\nAddress - %s\nPhone - %s\nNumber of rooms - %d\nNumber of luxe rooms - %d\nNumber of free rooms - %d\n\n",
        save_i+1,instanses[save_i].name,instanses[save_i].stars, instanses[save_i].adress, instanses[save_i].phone, instanses[save_i].default_rooms, instanses[save_i].luxe_rooms, instanses[save_i].free_rooms);
    }
}

void input_contents(struct hotel *instanses){
    fflush(stdin); // убирает все \n которые могут помешать считыванию
    fgets(instanses->name, 50, stdin);
    instanses->name[strcspn(instanses->name, "\n")] = 0;
    scanf("%lf",&instanses->stars);
    fflush(stdin);
    fgets(instanses->adress, 50, stdin);
    instanses->adress[strcspn(instanses->adress, "\n")] = 0;
    fgets(instanses->phone, 50, stdin);
    instanses->phone[strcspn(instanses->phone, "\n")] = 0;
    scanf("%d %d %d",&instanses->default_rooms,&instanses->luxe_rooms,&instanses->free_rooms);
}