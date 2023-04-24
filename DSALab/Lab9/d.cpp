// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int findSubArrays(vector<int> &arr, int n, int k)
{
    int minsum = 0, result = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        minsum += arr[i] - k;

        if (minsum == 0)
            result++;

        if (mp.find(minsum) != mp.end())
            result += mp[minsum];

        mp[minsum]++;
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findSubArrays(arr, n, k) << endl;
}
