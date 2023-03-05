#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int openCount = 0, closeCount = 0;
    int leftAdd = 0, rightAdd = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            openCount++;
        } else {
            closeCount++;
        }

        // If the count of closing brackets is greater than the count of opening brackets,
        // we need to add an opening bracket to the left of the current position.
        if (closeCount > openCount) {
            leftAdd++;
            openCount++;
        }
    }

    // Add closing brackets to the right of the sequence if necessary
    rightAdd = openCount - closeCount;

    // The minimum number of operations needed to make the sequence regular is the sum of
    // the number of opening and closing brackets added.
    cout << leftAdd + rightAdd << endl;

    return 0;
}
