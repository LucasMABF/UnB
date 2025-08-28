// Cidades Planejadas
// https://codeforces.com/group/btcK4I5D5f/contest/537349/problem/C
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  char city[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> city[i][j];
    }
  }

  bool simetric = true;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (city[i][j] != city[j][i]) simetric = false;
    }
  }

  if (simetric) {
    cout << "Sim" << endl;
  } else {
    cout << "Nao" << endl;
  }

  return 0;
}
