// Relogio e linhas
// https://codeforces.com/group/YPSel1QSwP/contest/634521/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }

    if (c > d) {
      int temp = c;
      c = d;
      d = temp;
    }

    if (((c > a && c < b) || (d > a && d < b)) &&
        !((c > a && c < b) && (d > a && d < b))) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
