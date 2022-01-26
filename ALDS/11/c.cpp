#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
const int inf = 1e9;

void bfs(int s, const Graph& g, vector<int>& d) {
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto next : g[u]) {
      if (d[next] != -1) continue;
      d[next] = d[u] + 1;
      q.push(next);
    }
  }
}

int main() {
  int n;
  cin >> n;

  Graph g(n);
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

  vector<int> d(n, -1);
  d[0] = 0;

  bfs(0, g, d);
  rep(i, n) {
    cout << i + 1 << " " << d[i] << endl;;
  }
  return 0;
}