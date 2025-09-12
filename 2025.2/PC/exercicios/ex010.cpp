// Little Artem
// https://codeforces.com/problemset/problem/1333/a
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;

    for (int j = 0; j < n - 1; j++) {
      cout << "B";
      for (int k = 1; k < m; k++) {
        cout << "W";
      }
      cout << "\n";
    }

    for (int k = 0; k < m; k++) {
      cout << "B";
    }
    cout << "\n";
  }

  return 0;
}
