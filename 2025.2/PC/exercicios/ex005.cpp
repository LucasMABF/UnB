// Nastya and an Array
//https://codeforces.com/problemset/problem/992/a
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  set<int> done;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    done.insert(x);
  }

  int result = done.size();
  if (done.count(0) > 0) {
    result--;
  }

  cout << result << "\n";

  return 0;
}
