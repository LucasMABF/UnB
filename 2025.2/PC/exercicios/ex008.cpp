// Array Coloring
// https://codeforces.com/problemset/problem/1857/a
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int odds = 0;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      if (x % 2 == 1) {
        odds++;
      }
    }

    if(odds % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
