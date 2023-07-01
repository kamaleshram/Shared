#include <bits/stdc++.h>
using namespace std;

int minCoupons(int k, vector<int> &coupons)
{
    int n = coupons.size();
    vector<int> dp(k + 1, INT_MAX); // dp[i] stores minimum number of coupons needed to make value i
    dp[0] = 0;                      // base case: 0 coupons needed to make value 0

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coupons[j] <= i)
            {
                int temp = dp[i - coupons[j]];
                if (temp != INT_MAX)
                    dp[i] = min(dp[i], temp + 1);
            }
        }
    }

    return (dp[k] == INT_MAX) ? -1 : dp[k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> coupons(n);
    for (int i = 0; i < n; i++)
        cin >> coupons[i];

    cout << minCoupons(k, coupons) << endl;
    return 0;
}