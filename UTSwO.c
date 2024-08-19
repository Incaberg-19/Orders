#include <stdio.h>
#include <math.h>

int main(void){
  double a,t;
  scanf("%lf %lf",&a,&t);
  int N=31,M=101;
  int c=15,d=50; //координаты центра

  for (int i=15; i>=0; i--){
    for (int x=(-M+1)/2; x<0; x++){
      char symvol='#';  
      if (i==0) symvol = '@';
      int sign=1;
      long double y=a*exp(-x/t);
      size_t y_int = (int)y; 
      if (y_int<0) sign=-1;
      if ((abs(x)+d)<M && (sign*y_int+c)<N && y_int==i){
        symvol='*';
      }
      printf("%c",symvol);
    }
    printf("@");

    for (int x=1; x<M/2; x++){
      char symvol='#';
      if (i==0) symvol = '@';
      int sign=1;
      long double y=a*exp(-x/t);
      size_t y_int = (int)y; 
      if (y_int<0) sign=-1;
      if ((x+d)<M && (sign*y_int+c)<N && y_int==i){
        symvol='*';
      }
      printf("%c",symvol);
    }
    printf("\n");
  }

  //ниже оси х

  for (int i=16; i<31; i++){
    for (int x=(-M+1)/2; x<0; x++){
      char symvol='#';  
      if (i==0) symvol = '@';
      int sign=1;
      long double y=a*exp(-x/t);
      size_t y_int = (int)y; 
      if (y_int<0) sign=-1;
      if ((abs(x)+d)<M && (sign*y_int+c)<N && -y_int+c==i){
        symvol='*';
      }
      printf("%c",symvol);
    }
    printf("@");

    for (int x=1; x<M/2; x++){
      char symvol='#';
      if (i==0) symvol = '@';
      int sign=1;
      long double y=a*exp(-x/t);
      size_t y_int = (int)y; 
      if (y_int<0) sign=-1;
      if ((x+d)<M && (sign*y_int+c)<N && -y_int+c==i){
        symvol='*';
      }
      printf("%c",symvol);
    }
    printf("\n");
  }

  return 0;
}