#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, k, n;
    cin >> m >> k >> n;

    vector<vector<int>> mtx1(m + 1, vector<int>(k + 1, 0));
    vector<vector<int>> mtx2(k + 1, vector<int>(n + 1, 0));
    vector<vector<int>> mtxpdt(m + 1, vector<int>(n + 1, 0));

    int nz1, nz2;
    cin >> nz1;
    while (nz1--)
    {
        int i, j;
        cin >> i >> j;
        cin >> mtx1[i][j];
    }

    cin >> nz2;
    while (nz2--)
    {
        int i, j;
        cin >> i >> j;
        cin >> mtx2[i][j];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int a1 = 1; a1 <= k; a1++)
            {
                mtxpdt[i][j] += mtx1[i][a1] * mtx2[a1][j];
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mtxpdt[i][j] != 0)
                count++;
        }
    }

    cout << count << endl;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mtxpdt[i][j] != 0)
            {
                cout << i << ' ' << j << ' ' << mtxpdt[i][j] << endl;
            }
        }
    }
}