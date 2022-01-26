#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int now = 0;

void dfs(int v, const vector<vector<int>>& g, vector<int>& d, vector<int>& f, vector<bool>& seen) {
  seen[v] = true;
  now++;
  d[v] = now;
  for (auto next : g[v]) {
    if (seen[next]) continue;
    dfs(next, g, d, f, seen);
  }
  now++;
  f[v] = now;
}

int main() {
  int n;
  cin >> n;
  vector<int> d(n), f(n);
  vector<bool> seen(n, false);

  vector<vector<int>> g(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    u--;
    rep(j, k) {
      int v;
      cin >> v;
      v--;
      g[u].push_back(v);
    }
  }

  rep(i, n) {
    if (!seen[i]) dfs(i, g, d, f, seen);
  }
  
  rep(i, n) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
  return 0;
}