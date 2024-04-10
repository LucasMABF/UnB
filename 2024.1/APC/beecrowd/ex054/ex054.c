// 1144 - Sequência Lógica
#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        double a = pow(i, 2);
        double b = pow(i, 3);
        printf("%d %.0lf %.0lf\n", i, a, b);
        printf("%d %.0lf %.0lf\n", i, a + 1, b + 1);
    }   

    return 0;
}

// 00 01 00 01 00 01 00 01 00 
// 01 02 01 04 01 06 01 08 01 
// 01 06 01 18 01 36 01 60 01
// +12 +18 +24 

// 1 8 27 64 125 216
//  7 19  37 61 91
//   12 18 24  30
//     6  6  6   
