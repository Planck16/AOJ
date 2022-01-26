#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> fib(n+1);
  fib[0] = 1; fib[1] = 1;
  rep(i, n-1) {
    fib[i+2] = fib[i+1] + fib[i];
  }
  cout << fib[n] << endl;
  return 0;
}