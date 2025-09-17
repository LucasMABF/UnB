// Fashionable Array
// https://codeforces.com/group/YPSel1QSwP/contest/634981/problem/Extra2
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<int> list;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      auto idx = lower_bound(list.begin(), list.end(), x);
      list.insert(idx, x);
    }

    if ((list[0] + list[list.size() - 1]) % 2 == 0) {
      cout << "0\n";
      continue;
    }

    int inicio = 0;
    int fim = 0;

    bool first = list[0] % 2 == 0;
    for (int j = 1; j < n; j++) {
      if ((list[j] % 2 == 0) != first) {
        inicio = j;
        break;
      }
    }

    bool last = list[list.size() - 1] % 2 == 0;
    for (int j = list.size() - 2; j >= 0; j--) {
      if ((list[j] % 2 == 0) != last) {
        fim = n - 1 - j;
        break;
      }
    }

    cout << min(inicio, fim) << "\n";
  }

  return 0;
}
