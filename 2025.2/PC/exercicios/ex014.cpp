// Sr. Sabe-tudo
// https://codeforces.com/group/YPSel1QSwP/contest/634521/problem/D

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

    int menor1 = -1;
    int menor2 = -1;
    int menor3 = -1;

    for (int j = 0; j < n; j++) {
      int m;
      char s1, s2;
      cin >> m >> s1 >> s2;

      if (s1 == '1' && s2 == '1') {
        if (m < menor3 || menor3 == -1) {
          menor3 = m;
        }
      } else if (s1 == '1') {
        if (m < menor1 || menor1 == -1) {
          menor1 = m;
        }
      } else if (s2 == '1') {
        if (m < menor2 || menor2 == -1) {
          menor2 = m;
        }
      }
    }

    if (menor1 == -1 || menor2 == -1) {
      if (menor3 == -1) {
        cout << "-1\n";
      } else {
        cout << menor3 << "\n";
      }
      continue;
    } else {
      if (menor3 == -1) {
        cout << menor1 + menor2 << "\n";
        continue;
      }
    }

    if (menor1 + menor2 < menor3) {
      cout << menor1 + menor2 << "\n";
    } else {
      cout << menor3 << "\n";
    }
  }

  return 0;
}
