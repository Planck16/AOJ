#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  Node *prev, *next;
};

struct Mylist{
  Node *nil;

  Mylist() {
    nil = (Node *)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
  }

  void push_front(int key) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;

    // nil -> x -> nil.next
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
  }

  Node* search(int key) {
    Node *cur = nil->next;
    while (cur != nil && cur->key != key) {
      cur = cur->next;
    }
    return cur;
  }

  void del(Node *t) {
    // t.prev -> t -> t.next
    if (t != nil) {
      t->prev->next = t->next;
      t->next->prev = t->prev;
      free(t);
    }
  }

  void pop_front() {
    del(nil->next);
  }

  void pop_back() {
    del(nil->prev);
  }

  void erase(int key) {
    Node *t = search(key);
    del(t);
  }

  void print() {
    Node *cur = nil->next;
    while (cur != nil) {
      if (cur != nil->next) printf(" ");
      printf("%d", cur->key);
      cur = cur->next;
    }
    printf("\n");
  }
};

int main() {
  int n;
  cin >> n;
  string com;
  int x;
  Mylist li;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      scanf("%d", &x);
      li.push_front(x);
    }
    else if (com == "delete") {
      scanf("%d", &x);
      li.erase(x);
    }
    else if (com == "deleteFirst") {
      li.pop_front();
    }
    else if (com == "deleteLast") {
      li.pop_back();
    }
  }

  li.print();
  return 0;
}