// Lista 1 - C - time-conversion
#include <string.h>

int main(){

  int hours;
  int minutes;
  int seconds;
  char ampm[3];
  scanf("%d:%d:%d%s", &hours, &minutes, &seconds, ampm);

  if(hours == 12){
    if(ampm[0] == 'A'){
      hours = 0;
    }
  }else{
    if(ampm[0] == 'P'){
      hours += 12;
    }
  }

  printf("%02d:%02d:%02d\n", hours, minutes, seconds);
  
  
  return 0;
}

