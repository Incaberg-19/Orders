#include <stdio.h>
#include <math.h>
int main(){
    double x=0,h=0,result=0;
    scanf("%lf",&h);
    do
    {
        result=8*x*x*x*cos(x);
        printf("%lf - %lf\n",x,result);
        x=x+h;
    } while (x>=0.0 && (x<=(1.0+1e-20)));

    printf("\nNext cycle\n");

    for (x;x>1.0 && x<=(2.0+1e-20);x=x+h){
        result=log10(1+sqrt(x))-cos(x);
        printf("%lf - %lf\n",x,result);
    }
}