#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    map<int, set<int>> freqMap;
    for (int i = 1; i <= m; i++)
    {
        freqMap[a[i]].insert(i);
    }

    vector<int> maxFreq(n + 1, -1);
    for (int i = m; i <= n; i++)
    {
        int left = i - m + 1;
        int removed = a[left - 1];
        int added = a[i];
        freqMap[removed].erase(left - 1);
        freqMap[added].insert(i);
        for (auto it = freqMap.begin(); it != freqMap.end(); it++)
        {
            if (it->second.size() == k)
            {
                maxFreq[left] = max(maxFreq[left], it->first);
            }
        }
    }

    for (int i = 1; i <= n - m + 1; i++)
    {
        cout << maxFreq[i] << "\n";
    }

    return 0;
}\
