#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

bool linearsearch(vector<int> &a, int key) {
  int i = 0;
  int n = a.size()-1;
  a[n] = key;
  while (a[i] != key) i++;
  if (i != n) return true;
  else return false;
}

int main() {
  int n;
  cin >> n;

  vector<int> s(n+1);
  rep(i, n) cin >> s[i];

  int q;
  cin >> q;

  vector<int> t(q);
  rep(i, q) cin >> t[i];


  int ans = 0;
  rep(i, q) {
    int key = t[i];
    if (linearsearch(s, key)) ans++;
  }

  cout << ans << endl;
  return 0;
}