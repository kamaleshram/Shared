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
    if (n % 2 == 0)
    {
        int l = 0, r = n / 2;
        while (l < n / 2 && r < n)
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
    }
    else
    {
        int l = 0, r = n / 2 + 1;
        while (l < n / 2 && r < n)
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
    }

    cout << count << endl;
}