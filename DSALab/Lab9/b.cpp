#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int presum[n], leftcand[n], rightcand[n];
    string a;
    cin >> a;

    if (a[0] == '*')
        presum[0] = 1;
    else
        presum[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int val = 0;
        if (a[i] == '*')
            val = 1;

        presum[i] = presum[i - 1] + val;
    }

    if (a[0] == '|')
        leftcand[0] = 0;
    else
        leftcand[0] = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == '|')
            leftcand[i] = i;
        else
            leftcand[i] = leftcand[i - 1];
    }

    if (a[n] == '|')
        rightcand[0] = n - 1;
    else
        rightcand[0] = n;

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] == '|')
            rightcand[i] = i;
        else
            rightcand[i] = rightcand[i + 1];
    }

    while (k--)
    {
        int l, r;
        cin >> l >> r;

        int left = rightcand[l], right = leftcand[r];

        if (left < right)
            cout << presum[right] - presum[left] << endl;
        else
            cout << 0 << endl;
    }
}