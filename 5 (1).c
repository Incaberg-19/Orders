#include <stdio.h>
#include <math.h>
int recursion(int a, int b) {
    if (b == 0) {
        return 0;
    } else {
        return (b>0) ? (a + recursion(a, b - 1)) : (a + recursion(a, abs(b) - 1))*-1;
    }
}

int cycle(int a, int b){
    int result = 0,sign=1;
    for (int i = 0; i < abs(b); i++) {
        result += a;
    }
    if (b<0) sign=-1;
    return result*sign;
}
int main(void){
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    printf("Cycle - %d\n",cycle(a,b));
    printf("Recursion - %d\n",recursion(a,b));
}

