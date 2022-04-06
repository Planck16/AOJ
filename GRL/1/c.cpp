#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // abs, sqrt, cos, ...
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


const ll inf = 2e18;
ll dist[110][110];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  // 無限大か0に初期化
  rep(i, n) rep(j, n) {
    if (i == j) dist[i][j] = 0;
    else dist[i][j] = inf;
  }

  // コストを設定
  rep(i, m) {
    ll s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  rep(k, n) rep(i, n) rep(j, n) {
    if (dist[i][k] == inf || dist[k][j] == inf) continue;

    chmin(dist[i][j], dist[i][k] + dist[k][j]);
  }

  rep(i, n) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << "\n";
      return 0;
    }
  }

  rep(i, n) {
    rep(j, n) {
      if (j) cout << " ";

      if (dist[i][j] == inf) {
        cout << "INF";
      }
      else {
        cout << dist[i][j];
      }
    }

    cout << "\n";
  }
  return 0;
}