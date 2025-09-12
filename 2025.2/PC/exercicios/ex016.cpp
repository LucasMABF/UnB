// Negatives and Positives
// https://codeforces.com/group/YPSel1QSwP/contest/634521/problem/Extra2

#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    long long int soma = 0;
    int negativos = 0;
    int menor;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      soma += abs(x);

      if (j == 0) {
        menor = abs(x);
      } else if (abs(x) < menor) {
        menor = abs(x);
      }

      if (x < 0) {
        negativos++;
      }
    }

    if (negativos % 2 == 1) {
      soma -= 2 * menor;
    }

    cout << soma << "\n";
  }

  return 0;
}
