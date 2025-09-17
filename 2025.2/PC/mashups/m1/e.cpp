// The Legend of Freya the Frog
// https://codeforces.com/group/YPSel1QSwP/contest/634981/problem/Extra1
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    int result = 2 * ceil(max(x, y) / (double)k);

    if (ceil(x / (double)k) > ceil(y / (double)k)) {
      result--;
    }

    cout << result << "\n";
  }

  return 0;
}
