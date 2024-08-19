#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int IsWordPolindrom(char *a);
void fillzero(char *a, int N);
void allif(char *a, char *b, char *c, int N);
void output(char *c);
int main(){
    char *a=NULL;
    scanf("%m[^\n]",&a);
    int N=strlen(a)+1;
    char b[N];
    char c[N];
    fillzero(c,N);
    allif(a,b,c,N);
    output(c);
    free(a);
    return 0;
}

int IsWordPolindrom(char *a){
    int left=0;
    int right=strlen(a)-1;
    while(left<right){
        if (a[left]!=a[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

void fillzero(char *a, int N){
    for (int i=0; i<N; i++){
        a[i]='\0';
    }
}

void allif(char *a, char *b, char *c, int N){
    int j=0;
    for (int i=0; i<N; i++){
        if ((a[i]!='\0') && (a[i]!=' ')){
            b[j++]=a[i];
        } else{
            b[j]='\0';
            j=0;
            if (IsWordPolindrom(b)==1){
                if (strlen(b)>strlen(c)){
                    strcpy(c,b);
                }
            }
        }
    }
}

void output(char *c){
    if (strlen(c)==0){
        printf("Nothing found");
    } else{
        if (strlen(c)==1){
            printf("Incorrect variable");
        } else{
            printf("%s",c);}
    }
}