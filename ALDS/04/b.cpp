#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

bool bs(vector<int> &a, int key) {
  int left = 0;
  int right = a.size() - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid] == key) return true;
    else if (a[mid] < key) left = mid + 1;
    else if (key < a[mid]) right = mid - 1;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  
  int q;
  cin >> q;

  int cnt = 0;
  rep(i, q) {
    int t;
    cin >> t;
    if(bs(s, t)) cnt++;
  }

  cout << cnt << endl;
  return 0;
}