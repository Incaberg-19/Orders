#include <stdio.h>
#include <string.h>
struct autoparts
{
    char stamp[50];
    char model[50];
    int value;
};

void input_contents(struct autoparts *instanses);

int main(void){
    int count_of_instanses=0,size=100;
    struct autoparts instanses[size];
    memset(instanses,0,sizeof(instanses));
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
    return 0;
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