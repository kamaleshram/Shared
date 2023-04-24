#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int total_a = accumulate(a.begin(), a.end(), 0);
    int total_b = accumulate(b.begin(), b.end(), 0);

    if (total_a != total_b) {
        int d = abs(total_a - total_b);
        if (d % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (abs(a[i] - b[j]) == d / 2) {
                cout << "Yes" << endl;
                return 0;
            } else if (a[i] > b[j]) {
                i++;
            } else {
                j++;
            }
        }

        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
