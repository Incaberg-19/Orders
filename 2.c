#include <stdio.h>
#include <math.h>
int sgn(double x) {
    if (x==0.0){
        return 0;
    } else if(x>0.0){
        return 1;
    } else if (x<0.0){
        return -1;
    }
}
int main(){
    double x=0,y=0,z=0;
    scanf("%lf",&x);
    if (x>0){
        y=(sqrt(x)/(sin(3.14*x)));
        printf("y - %lf\n",y);
        z=sgn(y);
        printf("z - %lf\n",z);
    } else{
        printf("Incorrect variable");
    }
    return 0;
}