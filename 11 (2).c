#include <stdio.h>
#include <string.h>
struct computer_companies
{
    char name_of_company[100];
    char processor[100];
    int RAM;
    int hard_disk_space;
    char video_card[100];
    double value;
    int year_of_purchase;
};

void input_contents(struct computer_companies *objects);
void find_most_old(struct computer_companies *objects, int count_of_objects);

int main(void){
    int count_of_objects=0,size=100;
    struct computer_companies objects[size];
    memset(objects,0,sizeof(objects));
    while(1){
        printf("1 - просмотреть список экземпляров\n2 - добавить новый экземпляр\n3 - удалить экземпляр\n4 - вывести компьютеры требующие обновления\n5 - выйти\n");
        int key=0;
        scanf("%d",&key);
        if (key==5){
            break;
        }
        if (key==4){
            find_most_old(objects, count_of_objects);
        }
        if (key==1){
            for (int i=0; i<count_of_objects; i++){
                printf("Номер экземпляра - %d\nНаименование фирмы - %s\nПроцессор - %s\nОбъём ОЗУ - %d\nОбъём жёсткого диска - %d\nНаименование видеокарты - %s\nЦена - %lf\nГод закупки - %d\n\n",
                i+1,objects[i].name_of_company,objects[i].processor,objects[i].RAM,objects[i].hard_disk_space,objects[i].video_card,objects[i].value,objects[i].year_of_purchase);
            }
        }
        //i+1 показывает номер экземпляра
        if (key==2){
            input_contents(&objects[count_of_objects]);
            count_of_objects++;
        }
        if (key==3){
            printf("1 - удалить последний экземпляр\n2 - удалить по номеру\n3 - удалить всё\n4 - выйти\n");
            scanf("%d",&key);
            if (key==4) continue;
            if (key==3){
                memset(objects,0,sizeof(objects));
                count_of_objects=0;
            }
            if (key==1){
                memset(&objects[count_of_objects-1], 0, sizeof(struct computer_companies));
                count_of_objects--;
            }
            if (key==2){
                printf("Введите номер экземпляра - ");
                scanf("%d",&key); //number is key-1
                if (key-1<count_of_objects){
                for (int i = key-1; i < count_of_objects+1; i++) {
                    objects[i] = objects[i + 1];
                }
                if (count_of_objects>0) count_of_objects--;
                } else{
                    printf("Такого номера экземпляра не существует\n");
                }
            }
        }
    }
    return 0;
}

void find_most_old(struct computer_companies *objects, int count_of_objects){
    int check=0,key_for_check_objects_old=0;
    if (count_of_objects==0){
        printf("Экземпляров не найдено\n");
        return;
    }
    for (int i=0; i<count_of_objects; i++){
        if (objects[i].year_of_purchase<2018){
            printf("Номер экземпляра - %d\nНаименование фирмы - %s\nПроцессор - %s\nОбъём ОЗУ - %d\nОбъём жёсткого диска - %d\nНаименование видеокарты - %s\nЦена - %lf\nГод закупки - %d\n\n",
            i+1,objects[i].name_of_company,objects[i].processor,objects[i].RAM,objects[i].hard_disk_space,objects[i].video_card,objects[i].value,objects[i].year_of_purchase);
        key_for_check_objects_old=1;
        }

    }
    if (key_for_check_objects_old==0){
        printf("Компьютеры не нуждаются в обновлении\n");
    }
}

void input_contents(struct computer_companies *objects){
    fflush(stdin); // это нужно для того чтобы убрать лишние \n в буффере (чтобы они не записывались к нам в массив)
    //LINUX: getchar();
    fgets(objects->name_of_company, 50, stdin);
    objects->name_of_company[strcspn(objects->name_of_company, "\n")] = 0;
    fgets(objects-> processor, 50, stdin);
    objects-> processor[strcspn(objects->processor, "\n")] = 0;
    scanf("%d",&objects->RAM);
    fflush(stdin);
    scanf("%d",&objects->hard_disk_space);
    fflush(stdin);
    fgets(objects->video_card, 50, stdin);
    objects->video_card[strcspn(objects->video_card, "\n")] = 0;
    scanf("%lf",&objects->value);
    fflush(stdin);
    scanf("%d",&objects->year_of_purchase);
    fflush(stdin);
}