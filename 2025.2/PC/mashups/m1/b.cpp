// It's Time To Duel
// https://codeforces.com/group/YPSel1QSwP/contest/634981/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    bool invalid = false;
    int soma = 0;
    int last;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      soma += x;

      if (j == 0) {
        last = x;
        continue;
      }

      if (last == 0 and x == 0) {
        invalid = true;
      }

      last = x;
    }

    if (invalid or soma > n - 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
