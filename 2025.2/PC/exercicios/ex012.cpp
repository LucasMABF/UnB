// Os Números de Saldanha
// https://codeforces.com/group/YPSel1QSwP/contest/634521/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> square;

  for (int i = 0; i < 4; i++) {
    int x;
    cin >> x;

    auto idx = upper_bound(square.begin(), square.end(), x);
    square.insert(idx, x);
  }

  for (int i = 0; i < 3; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << square[3] - square[i];
  }

  cout << "\n";

  return 0;
}
