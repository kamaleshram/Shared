#include <bits/stdc++.h>

using namespace std;

int findSumSubRanges(vector<int> input, int n)
{
    int columnsum = 1 - n, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += columnsum * input[i];
        columnsum += 2;
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    cout << findSumSubRanges(input, n) << endl;
}