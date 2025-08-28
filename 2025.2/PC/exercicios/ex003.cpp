// Trailing Zeros
// https://cses.fi/problemset/task/1618
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned int n;
  cin >> n;

  unsigned int result = 0;
  unsigned int powers = 5;
  while (n >= powers) {
    result += n/powers;
    powers *= 5;
  }

  cout << result << "\n";

  return 0;
}
