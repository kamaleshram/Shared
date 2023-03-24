#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int price[n], spread[n];

    for (int i = 0; i < n; i++)
        cin >> price[i];

    stack <int> s;

    for (int i = 0; i < n; i++) {
      while (!(s.empty()) && (price[s.top()] <= price[i]))
        s.pop();

      spread[i] = s.empty() ? i + 1 : i - s.top();
      s.push(i);
    }

    for (int i = 0; i < n; i++)
        printf("%d ", spread[i]);
}