#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, count = 0;
    cin >> n >> d;
    vector<int> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input.begin(), input.end());
    int l = 0, r = 0;

    while (r < n)
    {
        if (input[r] - input[l] >= d)
        {
            count++;
            l++;
            r++;
        }

        else
            r++;
    }

    cout << count << endl;
}