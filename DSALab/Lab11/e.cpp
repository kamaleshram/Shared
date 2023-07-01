#include <bits/stdc++.h>
using namespace std;

int matrixMul(vector<int> &p)
{
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i < n + 1; i++)
        cin >> p[i];

    cout << matrixMul(p) << endl;

    return 0;
}