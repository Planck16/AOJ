#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

bool IsPrime(long long n) {
  if (n <= 1) return false;

  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }

  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll cnt = 0;
  rep(i, n) {
    ll m;
    cin >> m;

    if (IsPrime(m)) ++cnt;
  }

  cout << cnt << "\n";
  return 0;
}