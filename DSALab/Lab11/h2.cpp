#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
    int n = str.length(), result = 0;

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            st.push(i);
        else
        {
            if (!st.empty())
                st.pop();
            if (!st.empty())
                result = max(result, i - st.top());
            else
                st.push(i);
        }
    }

    return result;
}

// Driver code
int main()
{
    string str;
    cin >> str;

    // Function call
    cout << findMaxLen(str) << endl;
    return 0;
}
