// Lista 02 - 1061 - Tempo de um Evento
#include <stdio.h>

int main(){
    int dia_inicio;
    scanf("Dia %d", &dia_inicio);
    int horas_inicio[3];
    scanf("%d : %d : %d", &horas_inicio[0], &horas_inicio[1], &horas_inicio[2]);
    getchar(); // remove \n from input buffer

    int dia_final;
    scanf("Dia %d", &dia_final);
    int horas_final[3];
    scanf("%d : %d : %d", &horas_final[0], &horas_final[1], &horas_final[2]);
    int segundos = horas_final[2] - horas_inicio[2];
    if(segundos < 0){
        segundos += 60;
        horas_final[1]--;
    }
    int minutos = horas_final[1] - horas_inicio[1];
    if(minutos < 0){
        minutos += 60;
        horas_final[0]--;
    }
    int horas = horas_final[0] - horas_inicio[0];
    if(horas < 0){
        horas += 24;
        dia_final--;
    }
    int dias = dia_final - dia_inicio;

    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", dias, horas, minutos, segundos);

    return 0;
}
