#include <stdio.h>
#include <math.h>
int main(){
    double x=0,y=0,z=0;
    scanf("%lf",&x);
    if ((x>0.0) && (cos(log(5*sqrt(sin(sqrt(x)))))>0.0)){
        y=5.0*sqrt(sin(sqrt(x)));
        printf("y(x)=%lf\n",y);
        z=log10(cos(log(y)));
        printf("z(y)=%lf\n",z);
    } else{
        printf("incorrect variable");
    }
    return 0;
}