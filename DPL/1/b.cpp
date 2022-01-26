#include <bits/stdc++.h>
using namespace std;
int dp[110][10010];

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> val(n), wei(n);
  for (int i = 0; i < n; i++) cin >> val[i] >> wei[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i + 1][j] = dp[i][j];
      if (j - wei[i] >= 0) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - wei[i]] + val[i]);
      }
    }
  }

  cout << dp[n][w] << endl;
  return 0;
}