#include <bits/stdc++.h>
using namespace std;

int min_edit_distance(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dparr(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        dparr[i][0] = i;
    for (int j = 1; j <= m; j++)
        dparr[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dparr[i][j] = dparr[i - 1][j - 1];
            else
                dparr[i][j] = min({dparr[i - 1][j - 1], dparr[i - 1][j], dparr[i][j - 1]}) + 1;
        }
    }

    return dparr[n][m];
}

int main()
{
    int n, m;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> m;
    cin >> t;

    cout << min_edit_distance(s, t) << endl;
    return 0;
}