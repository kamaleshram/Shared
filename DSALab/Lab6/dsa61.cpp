#include <iostream>

using namespace std;

class MinStack {
public:
  int *s, topind, minval, capacity, minval_prev;

  MinStack() {
    s = new int[10000];
    topind = -1;
    capacity = 10000;
    minval = 9999999;
    minval_prev = minval;
  }

  void push(int val) {
    s[++topind] = val;
    if (minval > val) {
      minval_prev = minval;
      minval = val;
    }
  }

  void pop() {
    if (minval == s[topind]) {
      minval = minval_prev;
    }
    topind--;
  }

  int top() { return s[topind]; }

  int getMin() { return minval; }
};

int getInput() {
  int a;
  cin >> a;
  return a;
}

int main() {
  MinStack minStack;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    minStack.push(getInput());
  }

  int no;
  cin >> no;

  for (int i = 0; i < no; i++) {
    int a;
    cin >> a;
    switch (a) {
    case 1:
      int val;
      cin >> val;
      minStack.push(val);
      break;

    case 2:
      minStack.pop();
      break;

    case 3:
      cout << minStack.top() << endl;
      break;

    case 4:
      cout << minStack.getMin() << endl;
      break;
    default:
      cout << "Invalid Input" << endl;
    }
  }

  return 0;
}