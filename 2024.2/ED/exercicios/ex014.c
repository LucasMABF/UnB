// Lista 3 - E - Ice Cream Parlor
#include <stdio.h>

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int m;
    scanf("%d", &m);

    int n;
    scanf("%d", &n);
    
    int cost[n];
    for(int j = 0; j < n; j++){
      scanf("%d", &cost[j]);
    }
    
    for(int j = 0; j < n; j++){
      for(int k = j + 1; k < n; k++){
        if(cost[j] + cost[k] == m){
          printf("%d %d\n", j + 1, k + 1);
        }
      }
    }

  }

  return 0;
}

