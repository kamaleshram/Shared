#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, bottles = 0, happiness = 0, testhappiness = 0;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        input.push_back(val);
    }

    sort(input.begin(), input.end(), greater<>());

    for (auto i : input)
    {
        testhappiness += i;
        if (testhappiness >= 0)
        {
            happiness += i;
            bottles++;
        }
        else
            break;
    }

    cout << bottles << endl;
}