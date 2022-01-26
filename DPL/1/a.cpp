#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const int inf = 1e9;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> c(m + 1);
  for (int i = 1; i <= m; i++) cin >> c[i];

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, inf));

  // 金額を0にするコインの枚数は0枚なのでdp[i][0] = 0
  rep(i, m + 1) dp[i][0] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      
      // j - c[i] >= 0でないと、c[i]は選べない。
      // 選んだらjを超えてしまうから
      if (j >= c[i]) dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i]] + 1);
      else dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[m][n] << endl;
  return 0;
}