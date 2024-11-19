#include <stdio.h>
#include <math.h>

int main(){
  int n;
  scanf("%d", &n);

  double coelho_x, coelho_y, raposa_x, raposa_y;
  scanf("%lf %lf %lf %lf", &coelho_x, &coelho_y, &raposa_x, &raposa_y);

  int escapou = 0;
  for(int i = 0; i < n; i++){
    double x, y;
    scanf("%lf %lf", &x, &y);

    if(pow(coelho_x - x, 2) + pow(coelho_y - y, 2) <= (pow(raposa_x - x, 2) + pow(raposa_y - y, 2)) / 4){
      printf("O coelho pode escapar pelo buraco (%.3lf,%.3lf).\n", x, y);
      escapou = 1;
      break;
    }
  }

  if(!escapou){
    printf("O coelho nao pode escapar.\n");
  }

  return 0;
}

