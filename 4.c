#include <stdio.h>
#include <math.h>
double obl(double n);
int main(void){
    double I1=0, I2=0.1, e=0, n=2;
    char ch;
    scanf("%lf%c",&e);
    while ((fabs(I2-I1))>e){
        I1=obl(n);
        I2=obl(2*n);    
        n=2*n;
    }
    printf("%0.5lf\n",I1);
    return 0;
}

double obl(double n){
    double h=0, sum=0, f=0, x1=-1, x2=1 + h / 2;
    h=2.0/n;
    for (int i=0; i<n; i++){
        x1 += h;
        x2 += h;
        if (x1>=-1.0 && x1<=1.0){
            f=exp(-2*sin(x1));
            sum=sum+f;
        }
        if(x2>1.0 && x2<=2.0){
            f=pow(x2,2.0) - (1/tan(x2)); 
            sum=sum+f;
        }
    }
    sum=sum*h;
    return sum;
}