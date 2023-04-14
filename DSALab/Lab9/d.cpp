// Wrong soluti0n
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    vector<double> prefix_sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    map<double, int> cnt;
    for (int r = 1; r <= n; r++)
    {
        double l_sum = prefix_sum[r] - k * r;
        if (cnt.count(l_sum))
        {
            ans += cnt[l_sum];
        }
        cnt[l_sum + k * r] += 1;
    }

    cout << ans << endl;
    return 0;
}
