#include <bits/stdc++.h>

using namespace std;

int max_nested_dolls(vector<pair<int, int>>& dolls) {
    int n = dolls.size();
    sort(dolls.begin(), dolls.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    vector<int> nesting;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(nesting.begin(), nesting.end(), dolls[i].second);
        if (it == nesting.end()) {
            nesting.push_back(dolls[i].second);
        } else {
            *it = dolls[i].second;
        }
    }

    return nesting.size();
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> dolls(n);
    for (int i = 0; i < n; i++) {
        cin >> dolls[i].first >> dolls[i].second;
    }

    cout << max_nested_dolls(dolls) << endl;

    return 0;
}
