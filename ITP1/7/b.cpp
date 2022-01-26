#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  while (true) {
    int n, x;
    int cnt = 0;
    cin >> n >> x;
    if (n == 0 && x == 0) break;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = j + 1; k <= n; k++) {
          if (i + j + k == x) cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}