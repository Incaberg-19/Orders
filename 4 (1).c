#include <stdio.h>
#include <math.h>
double obl(double n);
int main(void){
    double I1=0, I2=1, e=0, n=1;
    scanf("%lf",&e);
    while ((fabs(I2-I1)/3)>e){
        I1=obl(n);
        I2=obl(2*n);
        n=2*n;
    }
    printf("%0.5lf\n",I2);
    return 0;
}

double obl(double n){
    double h=0, sum=0, f=0, x=0;
    h=2.0/n;
    for (int i=0; i<n; i++){
        x=(float)i*h+h/2;
        if (x<=1 && x>=0){
            f=sqrt(x+1)-sqrt(x)-0.5;
            sum=sum+f;
        } else if(x>1 && x<=2){
            f=exp(-x-1/x);
            sum=sum+f;
        }
    }
    sum=sum*h;
    return sum;
}