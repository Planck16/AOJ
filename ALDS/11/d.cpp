#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;

void dfs(int v, Graph& g, vector<bool>& seen, vector<int>& group, int id) {
  seen[v] = true;
  group[v] = id;
  for (auto next : g[v]) {
    if (seen[next]) continue;
    dfs(next, g, seen, group, id);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph g(n);
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    g[s].push_back(t);
    g[t].push_back(s);
  }

  vector<bool> seen(n);
  vector<int> group(n, -1);
  int id = 0;
  rep(i, n) {
    if (group[i] == -1) {
      dfs(i, g, seen, group, id);
      id++;
    }
  }

  int q;
  cin >> q;
  rep(i, q) {
    int s, t;
    cin >> s >> t;
    if (group[s] == group[t]) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}