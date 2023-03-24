#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }

    stack<int> s1, s2;

    if (maxIndex < n - 1)
    {
        for (int i = maxIndex + 1; i < n; i++)
        {
            s1.push(i);
        }
        for (int i = 0; i < maxIndex; i++)
        {
            s1.push(i);
        }
        s2.push(maxIndex);
    }
    else
    {
        for (int i = 0; i < maxIndex; i++)
        {
            s1.push(i);
        }
        s2.push(maxIndex);
    }

    int ans[n];
    ans[maxIndex] = -1;

    while (!s1.empty())
    {
        if (arr[s2.top()] > arr[s1.top()])
        {
            if (s1.top() < s2.top())
            {
                ans[s1.top()] = s2.top() - s1.top();
                s2.push(s1.top());
                s1.pop();
            }
            else
            {
                ans[s1.top()] = n - s1.top() + s2.top();
                s2.push(s1.top());
                s1.pop();
            }
        }
        else
        {
            s2.pop();
            if (s2.empty())
            {
                s2.push(s1.top());
                ans[s1.top()] = -1;
                s1.pop();
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}