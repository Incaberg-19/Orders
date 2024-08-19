#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void res(int *a, int n, int (*f)(int), void (*g)(int *,int));
void output(int *a,int n);
int prostli(int a);
int input_n(int *n);
void fill(int n, int a[]);
int main(){
    srand(time(NULL));
    int a;
    int b=input_n(&a);
    if (b==0){
        printf("incorrect variable");
        return 0;
    }
    int c[a];
    fill(a, c);
    res(c,a,prostli,output);
    return 0;
}

int input_n(int *n){
    char ch;
    if (scanf("%d%c",n,&ch)!=2 || ch!='\n' || *n<=0){
        return 0;
    } else{
        return 1;
    }
}

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = 1 + rand () % 1000; //от 1 до 1000
}

void output(int *a,int n){
    for (int i=0; i<n; i++){
        if ((i+1)==n){
            printf("%d\n",a[i]);
        } else{
            printf("%d ",a[i]);
        }
    }
}

int prostli(int a)
{
    if (a==1){
        return 0;
    }
    for (int i=0; i<a-1; i++)
    {
        for(int j=0; j<a; j++)
        {
            if (i*j==a)
            {
                return 0;
            }
        }
    }
    return 1;
}

void res(int *a, int n, int (*f)(int), void (*g)(int *,int)){
    g(a,n);
    int k=0,q=0,l=0,j=0;
    for (int i=0; i<n; i++){
        if (f(a[i])==1){
            k=k+1;
            q=i;
        }
        if (k==1){
            l=q;
        }
        if (k==2){
            j=q;
        }
    }
    if (k==0){
        printf("unusable variables");
    }
    if (k==1){
        printf("%d\n",a[l]);
    }
    if (k==2){
        int temp=a[l];
        a[l]=a[j];
        a[j]=temp;
        g(a,n);
    }
    if (k>2){
        for (int i=0; i<n; i++){
            if (f(a[i])==1){
                if ((i+1)==n){
                    printf("%d",i);
                } else{
                    printf("%d ",i);
                }
            }
        }
    }
}

