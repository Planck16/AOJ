#include <bits/stdc++.h>
using namespace std;

const int len = 100010;

struct P{
  string name;
  int t;
};

struct Myqueue{
  int head, tail;
  P s[len];

  Myqueue() {
    head = 0;
    tail = 0;
  }

  void push(P x) {
    s[tail] = x;
    tail = (tail + 1) % len;
  }

  P front() {
    P x = s[head];
    return x;
  }

  void pop() {
    head = (head + 1) % len;
  }

  bool empty() {
    if (head == tail) return true;
    else return false;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  P p[len];
  Myqueue que;

  for (int i = 0; i < n; i++) {
    cin >> p[i].name >> p[i].t;
    que.push(p[i]);
  }

  int now = 0;
  while (!que.empty()) {
    P x = que.front();
    if (q - x.t >= 0) {
      now += x.t;
      que.pop();
      cout << x.name << " " << now << endl;
    }
    else {
      now += q;
      x.t -= q;
      que.pop();
      que.push(x);
    }
  }
  return 0;
}