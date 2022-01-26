#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n, 0));
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    u--;
    rep(j, k) {
      int v;
      cin >> v;
      v--;
      g[u][v] = 1;
    }
  }
  rep(i, n) {
    rep(j, n) {
      if (j > 0) cout << " ";
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}