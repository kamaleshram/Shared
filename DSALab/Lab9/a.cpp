#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int ans = n;

    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        minheap.push(val);
        sum += val;

        if (sum < 0)
        {
            sum -= minheap.top();
            minheap.pop();
            ans--;
        }
    }

    cout << ans << endl;
}