#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  stack<pair<int, int> > s; // pair of student's assigned integer and number of rooms to cross
  for (int i = 0; i < n; i++) {
    int rooms = 0;
    while (!s.empty() && s.top().first < a[i]) {
      rooms += i - s.top().second; // number of rooms to cross to get pass
      s.pop();
    }
    if (!s.empty()) {
      rooms += i - n + s.top().second; // number of rooms to cross to get pass
                                       // from bottom of stack
    }
    s.push(make_pair(a[i], i)); // add current student to stack
    cout << rooms << " ";
  }
  cout << endl;
  return 0;
}
