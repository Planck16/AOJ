#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int NIL = -1;

struct Node{
  int p, l, r;
};

// 深さのセット
void setD(int u, int p, const vector<Node>& t, vector<int>& d) {
  d[u] = p;
  if (t[u].l != NIL) {
    setD(t[u].l, p + 1, t, d);
  }
  if (t[u].r != NIL) {
    setD(t[u].r, p, t, d);
  }
}

void print(int u, const vector<Node>& t, vector<int>& d) {
  printf("node %d: parent = %d, depth = %d, ", u, t[u].p, d[u]);
  if (t[u].p == NIL) cout << "root, ";
  else if (t[u].l == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  int c = t[u].l;
  cout << "[";
  
  for (int i = 0; c != NIL; i++, c = t[c].r) {
    if (i != 0) cout << ", ";
    cout << c;
  }

  cout << "]" << endl;
}

int main() {
  int n;
  cin >> n;

  vector<Node> t(n);
  rep(i, n) {
    t[i].p = NIL;
    t[i].l = NIL;
    t[i].r = NIL;
  }

  vector<int> d(n);
  
  rep(i, n) {
    int u, k;
    cin >> u >> k;

    int l;
    rep(j, k) {
      int c;
      cin >> c;
      if (j == 0) t[u].l = c;
      else t[l].r = c;
      l = c;
      t[l].p = u;
    }
  }

  // 根を特定
  int r = 0;
  rep(i, n) {
    if (t[i].p == NIL) r = i;
  }

  setD(r, 0, t, d);
  
  rep(i, n) print(i, t, d);
  return 0;
}