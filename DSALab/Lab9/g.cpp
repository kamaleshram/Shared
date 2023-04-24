#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end(), cmp);

    string k = "";
    for (int i = 0; i < n; i++)
        k += nums[i];

    cout << k << endl;
}
