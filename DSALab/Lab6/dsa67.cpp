#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int price[n];
    for(int i=0; i<n; i++) {
        cin >> price[i];
    }
    stack<int> s;
    int spread[n];
    for(int i=0; i<n; i++) {
        while(!s.empty() && price[s.top()]<=price[i]) {
            s.pop();
        }
        if(s.empty()) {
            spread[i] = i+1;
        } else {
            spread[i] = i - s.top();
        }
        s.push(i);
    }
    for(int i=0; i<n; i++) {
        cout << spread[i] << " ";
    }
    return 0;
}
