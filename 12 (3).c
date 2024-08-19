#include <stdio.h>
#include <string.h>
struct autoparts
{
    char stamp[50];
    char model[50];
    int value;
};

void Write_instanses(struct autoparts *instanses, int size);
void input_contents(struct autoparts *instanses);
void Read_instanses(struct autoparts *instanses, int maxSize,int *count_of_instanses);

int main(void){
    int count_of_instanses=0,size=100;
    struct autoparts instanses[size];
    memset(instanses,0,sizeof(instanses));
    Read_instanses(instanses,size,&count_of_instanses); //ф-ия считывания экземпляров из файла
    while(1){
        printf("Button '1' - check list\nButton '2' - add new instanses\nButton '3' - remove some instanse\nButton '4' - Exit\n");
        int key=0;
        scanf("%d",&key);
        if (key==4){
            break;
        }
        if (key==1){
            for (int i=0; i<count_of_instanses; i++){
                printf("Number of instanse-%d\nStamp - %s\nModel - %s\nValue - %d\n\n",i+1,instanses[i].stamp, instanses[i].model,instanses[i].value);
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
                memset(&instanses[count_of_instanses-1], 0, sizeof(struct autoparts));
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

void Read_instanses(struct autoparts *instanses, int maxSize, int* count_of_instances) {
    FILE *file = fopen("history_of_instanses.txt", "r");
    if (file == NULL) {
        return;
    }
    *count_of_instances=1;
    int i = 0;
   char line[256]; //сюда записывается полученная строка с помощью fgets
    while (i < maxSize && fgets(line, sizeof(line), file)) {
    if (strlen(line)==1) continue; //если строка пустая то возвращаемся в начало while
        strcpy(instanses[i].stamp, line);
        instanses[i].stamp[strcspn(instanses[i].stamp, "\n")] = 0;
        fgets(line, sizeof(line), file);
        strcpy(instanses[i].model, line);
        instanses[i].model[strcspn(instanses[i].model, "\n")] = 0;
        fgets(line, sizeof(line), file);
        sscanf(line, "%d", &instanses[i].value);
        i++;
   }

    *count_of_instances = i;

    fclose(file);
}

void Write_instanses(struct autoparts *instanses, int size) {
    FILE *file = fopen("history_of_instanses.txt", "w");
    if (file == NULL) { 
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n%s\n%d\n\n",
        instanses[i].stamp, instanses[i].model, instanses[i].value);   
    }

    fclose(file);
}

void input_contents(struct autoparts *instanses){
    fflush(stdin); // убирает все \n которые могут помешать считыванию
    // для LINUX getchar(); 
    fgets(instanses->stamp, 50, stdin);
    instanses->stamp[strcspn(instanses->stamp, "\n")] = 0;
    fgets(instanses->model, 50, stdin);
    instanses->model[strcspn(instanses->model, "\n")] = 0;
    scanf("%d",&instanses->value);
}