#include <stdio.h>

int main(){
  int d0, h0, m0, s0;
  scanf("%d %d:%d:%d", &d0, &h0, &m0, &s0);

  int d1, h1, m1, s1;
  scanf("%d %d:%d:%d", &d1, &h1, &m1, &s1);

  int dias = d1 - d0;

  int horas = h1 - h0;
  if(horas < 0){
    horas += 24;
    dias -= 1;
  }

  int minutos = m1 - m0;
  if(minutos < 0){
    minutos += 60;
    horas -= 1;
  }

  int segundos = s1 - s0;
  if(segundos < 0){
    segundos += 60;
    minutos -= 1;
  }


  if(dias < 0 || horas < 0 || minutos < 0 || segundos < 0){
    printf("Data invalida!\n");
  }else if(dias == 0 && horas == 0 && minutos == 0 && segundos == 0){
    printf("Data invalida!\n");
  }else{
    printf("%d dia(s)\n", dias);
    printf("%d hora(s)\n", horas);
    printf("%d minuto(s)\n", minutos);
    printf("%d segundo(s)\n", segundos);
  }

  return 0;
}

