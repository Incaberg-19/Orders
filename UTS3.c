#include <stdio.h>
#include <math.h>
void create_a_field(int N, int M, char field[N][M]);
void draw_a_field(int N, int M, char field[N][M]);
void create_function(int N, int M, char field[N][M],double a,double t);

int main(void){
  int N=31,M=101;
  double a=0,t=0;
  scanf("%lf %lf",&a,&t);
  char field[N][M];
  create_a_field(N,M,field);
  create_function(N,M,field,a,t);
  draw_a_field(N,M,field);
  return 0;
}

void create_function(int N, int M, char field[N][M],double a, double t){
  field[15][50]='O';
  //centre positions
  int c=15,d=50;
  for (int x=-M+1; x<M; x++){
    int sign=1;
    long double y=a*exp(-x/t);
    size_t y_int = (int)y; 
    if (y_int<0) sign=-1;
    if (x>0){
      if ((x+d)<M && (sign*y_int+c)<N){
        field[-y_int+c][x+d]='*';
      }
    } else{
      if (abs(x)>=0 && (abs(x)+d)<M && (sign*y_int+c)<N){
        field[-y_int+c][x+d]='*';
      }
    }
  }
}

void draw_a_field(int N, int M, char field[N][M]){
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      printf("%c",field[i][j]);
    }
    printf("\n");
  }
}

void create_a_field(int N, int M, char field[N][M]){
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      if (j==50 || i==15){
        field[i][j]='@';
      } else{
        field[i][j]='#';
      }
    }
  }
}