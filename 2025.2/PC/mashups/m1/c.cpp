// Preparing for the Exam
// https://codeforces.com/group/YPSel1QSwP/contest/634981/problem/C
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;

    int lists[m];
    for (int j = 0; j < m; j++) {
      cin >> lists[j];
    }

    long long unsigned int unknown = 1LL * n * (n + 1) / 2;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;

      unknown -= x;
    }

    for (int j = 0; j < m; j++) {
      if (k == n) {
        cout << "1";
        continue;
      }

      if (k < n - 1) {
        cout << "0";
        continue;
      }

      if (lists[j] == unknown) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << "\n";
  }

  return 0;
}
