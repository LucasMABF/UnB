// Barca de Shushi
// https://codeforces.com/group/YPSel1QSwP/contest/634521/problem/Extra1

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int current1 = 1;
  int current2 = 1;
  int maior = -1;
  int last;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (i == 0) {
      last = x;
      continue;
    }

    if (x == last) {
      if (x == 1) {
        current1++;
      } else {
        current2++;
      }
    }

    if (x != last || i == n - 1) {
      int m = min(current1, current2) * 2;

      if (m > maior) {
        maior = m;
      }

      if (x == 1) {
        current1 = 1;
      } else {
        current2 = 1;
      }
    }

    last = x;
  }

  cout << maior << "\n";

  return 0;
}
