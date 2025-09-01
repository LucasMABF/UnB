// Shape Perimeter
// https://codeforces.com/problemset/problem/2056/a
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n;
    cin >> m;

    int perimeter;
    for (int j = 0; j < n; j++) {
      int x, y;
      cin >> x;
      cin >> y;
      if (j == 0) {
        perimeter = 4 * m;
        continue;
      }

      perimeter += 2 * x + 2 * y;
    }
    cout << perimeter << "\n";
  }

  return 0;
}
