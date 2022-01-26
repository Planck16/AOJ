#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

struct UnionFind {
  vector<int> parent;

  UnionFind(int n) : parent(n, -1) {}

  int find(int x) {
    if (parent[x] < 0) return x;

    parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    // xを親に設定
    if (parent[x] > parent[y]) swap(x, y);
    parent[x] += parent[y];
    parent[y] = x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return -parent[find(x)];
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  UnionFind uf(n);

  rep(i, q) {
    int c, x, y;
    cin >> c >> x >> y;

    if (c == 0) uf.unite(x, y);
    else if (c == 1) {
      if (uf.same(x, y)) cout << 1 << "\n";
      else  cout << 0 << "\n";
    }
  }
  return 0;
}