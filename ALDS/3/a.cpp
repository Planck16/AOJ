#include <bits/stdc++.h>
using namespace std;

struct Mystack{
  int idx;
  vector<int> s;
  
  Mystack(int n) {
    idx = 0;
    s.assign(n + 1, 0);
  }

  void push(int x) {
    idx++;
    s[idx] = x;
  }

  int top() {
    return s[idx];
  }

  void pop() {
    s[idx] = 0;
    idx--;
  }

  int size() {
    return idx;
  }
  
  bool empty() {
    if (idx == 0) return true;
    else return false;
  }
};

int main() {
  Mystack stk(100);
  string s;
  int a, b;
  while (cin >> s) {
    if (isdigit(s[0])) {
      stk.push(stoi(s));
    }
    else {
      a = stk.top(); stk.pop();
      b = stk.top(); stk.pop();
      if (s == "+") stk.push(b + a);
      else if (s == "-") stk.push(b - a);
      else if (s == "*") stk.push(b * a);
    }
  }

  cout << stk.top() << endl;
  return 0;
}