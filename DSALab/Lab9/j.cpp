// C++ program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, max_platforms = 0, platforms = 0;
    cin >> n;
    multiset<pair<int, int>> pfms;
    for (int i = 0; i < n; i++)
    {
        int a, d;
        cin >> a >> d;
        pfms.insert(make_pair(a, 1));
        pfms.insert(make_pair(d, 0));
    }

    for (auto i : pfms)
    {
        if (i.second == 1)
            platforms++;
        else
            platforms--;

        max_platforms = max(platforms, max_platforms);
    }

    cout << max_platforms << endl;
}