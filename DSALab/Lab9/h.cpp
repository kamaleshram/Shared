#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<int> &a, int m, int mid)
{
    int students = 1;
    int pages = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > mid)
        {
            return false;
        }
        if (pages + a[i] > mid)
        {
            students++;
            pages = a[i];
            if (students > m)
            {
                return false;
            }
        }
        else
        {
            pages += a[i];
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int start = *max_element(a.begin(), a.end());
    int end = accumulate(a.begin(), a.end(), 0);
    int result = end;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (is_possible(a, m, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
