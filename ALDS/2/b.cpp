#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int selectionsort(vector<int> &a) {
  int sw = 0;
  int n = a.size();

  for (int i = 0; i < n - 1; i++) {
    int mnj = i;
    for (int j = i + 1; j < n; j++) {
      if (a[mnj] > a[j]) {
        mnj = j;
      }
    }
    if (a[i] > a[mnj]) {
      swap(a[i], a[mnj]);
      sw++;
    }
  }

  return sw;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int sw = selectionsort(a);

  rep(i, n) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;

  cout << sw << endl;
  return 0;
}