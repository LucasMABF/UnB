// Lista 05 - 1171 - Frequência de Números
#include <stdio.h>
int add(int *vec, int x, int len){
    for(int i = 0; i < len; i++){
        if(vec[i] == x){
            return i;
        }
    }
    vec[len] = x;
    return -1;
}

// sort both vectors by vec1
void sort(int *vec1, int *vec2, int n){
    int sorted = 0;
    while(! sorted){
        sorted = 1;
        for(int i = 0; i < n - 1; i++){
            if(vec1[i] > vec1[i + 1]){
                sorted = 0;
                int temp1 = vec1[i];
                int temp2 = vec2[i];
                vec1[i] = vec1[i + 1];
                vec2[i] = vec2[i + 1];
                vec1[i + 1] = temp1;
                vec2[i + 1] = temp2;
            }
        }
    }

}

int main(){
   int n;
   int len = 0;
   scanf("%d", &n);
   int numeros[n];
   int aparece[n];
   for(int i = 0; i < n; i++){
       int x;
       scanf("%d", &x);
       int j = add(numeros, x, len);

       if(j != -1){
           aparece[j] += 1;
       }else{
           aparece[len] = 1;
           len += 1;
       }
   }

   sort(numeros, aparece, len);

   for(int i = 0; i < len; i++){
       printf("%d aparece %d vez(es)\n", numeros[i], aparece[i]);
   }

    return 0;
}
