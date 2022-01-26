#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;

  vector<int> r(n);
  rep(i, n) cin >> r[i];

  int mn = r[0];
  int ans = -inf;

  for (int i = 1; i < n; i++) {
    ans = max(ans, r[i] - mn);
    mn = min(mn, r[i]);
  }

  cout << ans << endl;
  return 0;
}