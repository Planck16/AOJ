#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const int inf = 1e9;
const int mod = 1e9+7;

int bubblesort(vector<int> &a) {
  int n = a.size();
  bool flag = true;
  int sw = 0;
  for (int i = 0; flag; i++) {
    flag = false;
    for (int j = n-1; j >= i+1; j--) {
      if (a[j-1] > a[j]) {
        swap(a[j-1], a[j]);
        flag = true;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, n) cin >> a[i];
   int sw = bubblesort(a);

   rep(i, n) {
     if (i > 0) cout << " ";
     cout << a[i];
   }
   cout << endl;

   cout << sw << endl;
  return 0;
}