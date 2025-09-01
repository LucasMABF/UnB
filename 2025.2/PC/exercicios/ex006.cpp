// Blank Space
// https://codeforces.com/problemset/problem/1829/b
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

    int longest = 0;
    int current = 0;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      if (x == 0) {
        current++;
        continue;
      }

      if (current > longest) {
        longest = current;
      }
      current = 0;
    }

    if (current > longest) {
      longest = current;
    }

    cout << longest << "\n";
  }

  return 0;
}
