#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> s;
    int max_area = 0, i = 0;
    while (i < n) {
        if (s.empty() || a[s.top()] <= a[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            int area = a[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int area = a[top] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area);
    }

    cout << max_area << endl;

    return 0;
}
