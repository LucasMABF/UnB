// The Bento Box Adventure
// https://codeforces.com/group/YPSel1QSwP/contest/634981/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  int soma = 0;

  for (int i = 0; i < 4; i++) {
    int x;
    cin >> x;

    soma += x;
  }

  int total = 15; // 1 + 2 + 3 + 4 + 5
  cout << total - soma << "\n";

  return 0;
}
