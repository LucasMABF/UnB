// Variando Strings
// https://codeforces.com/group/YPSel1QSwP/contest/634521/problem/A

#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  getchar();

  for (int i = 0; i < t; i++) {
    vector<char> letters;
    char c;
    while (true) {
      c = getchar();
      if (c == '\n' || c == EOF)
        break;
      auto idx = upper_bound(letters.begin(), letters.end(), c);
      letters.insert(idx, c);
    }

    char last = letters[0];
    bool yes = true;
    for (size_t j = 1; j < letters.size(); j++) {
      if (letters[j] != ++last) {
        yes = false;
        break;
      }
    }

    if (yes) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
