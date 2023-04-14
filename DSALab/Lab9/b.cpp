#include <bits/stdc++.h>

using namespace std;

int findPlates(string input, int l, int r)
{
    int plates = 0;
    while (input[r] != '|')
        r--;
    while (input[l] != '|')
        l++;

    while (l < r)
    {
        if (input[l] == '*')
            plates++;
        l++;
    }

    return plates;
}

int main()
{
    int n, q;
    cin >> n >> q;

    string input;
    cin >> input;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << findPlates(input, l, r) << endl;
    }
}