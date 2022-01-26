#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

void printv(vector<int> a) {
  int len = a.size();
  rep(i, len) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void insertionsort(vector<int> a) {
  int len = a.size();
  for (int i = 1; i < len; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    printv(a);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  printv(a);
  insertionsort(a);
  return 0;
}