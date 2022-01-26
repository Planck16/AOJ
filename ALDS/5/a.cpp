#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool solve(const vector<int> a, int i, int m) {
  int n = a.size();
  if (m == 0) return true;
  else if (i >= n) return false;
  bool res = solve(a, i + 1, m) || solve(a, i + 1, m - a[i]);
  return res;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int q;
  cin >> q;

  rep(i, q) {
    int m;
    cin >> m;
    if (solve(a, 0, m)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}