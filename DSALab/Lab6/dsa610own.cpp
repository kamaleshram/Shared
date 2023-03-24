#include <iostream>
#include <stack>

using namespace std;

int getAns(string s) {
    int n = s.length(), open = 0, close = 0, addopen = 0, addclose = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '(')
        open++;
      else
        close++;
    
      if (close > open) {
        addopen++;
        open++;
      }
    }

    addclose = open - close;

    return addclose + addopen;
}

int main() {
    string s;
    cin >> s;

    cout << getAns(s);
}