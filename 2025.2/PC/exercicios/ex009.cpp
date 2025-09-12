// Number Spiral
// https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long int x, y;
    cin >> y >> x;

    long long int result;
    if (x >= y) {
      if (x % 2 == 0) {
        result = (x - 1) * (x - 1) + y;
      } else {
        result = x * x - y + 1;
      }
    } else {
      if (y % 2 == 0) {
        result = y * y - x + 1;
      } else{
        result = (y - 1) * (y - 1) + x;
      }
    }

    cout << result << "\n";
  }
  return 0;
}
