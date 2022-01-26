#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

struct Card{
  char suit, value;
};

void bubble(vector<Card> &c) {
  int n = c.size();
  bool flag = true;
  for (int i = 0; flag; i++) {
    flag = false;
    for (int j = n-1; j >= i+1; j--) {
      if (c[j-1].value > c[j].value) {
        Card tmp = c[j-1];
        c[j-1] = c[j];
        c[j] = tmp;
      }
      flag = true;
    }
  }
}

void selection(vector<Card> &c) {
  int n = c.size();
  int mnj = 0;
  for (int i = 0; i < n-1; i++) {
    mnj = i;
    for (int j = i+1; j < n; j++) {
      if (c[mnj].value > c[j].value) mnj = j;
    }
    if (mnj != i) {
      Card tmp = c[i];
      c[i] = c[mnj];
      c[mnj] = tmp;
    }
  }
}

void printv(const vector<Card> &c) {
  int n = c.size();
  rep(i, n) {
    if (i > 0) cout << " ";
    cout << c[i].suit << c[i].value;
  }
  cout << endl;
}

bool isstable(const vector<Card> &c1, const vector<Card> &c2) {
  int n = c1.size();
  bool stable = true;
  rep(i, n) {
    if (c1[i].suit != c2[i].suit) stable = false;
  }
  return stable;
}

int main() {
  int n;
  cin >> n;

  vector<Card> c1(n), c2(n);
  rep(i, n) cin >> c1[i].suit >> c1[i].value;
  rep(i, n) {
    c2[i].suit = c1[i].suit;
    c2[i].value = c1[i].value;
  }

  bubble(c1);
  printv(c1);
  cout << "Stable" << endl;

  selection(c2);
  printv(c2);
  bool stable = isstable(c1, c2);
  if (stable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  return 0;
}