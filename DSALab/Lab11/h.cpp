#include <bits/stdc++.h>
using namespace std;

int findLongestRBS(string s)
{
    int n = s.length();
    int max_len = 0;
    stack<int> st; // to store indices of opening brackets

    // initialize the stack with -1
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            // if a closing bracket is encountered
            if (!st.empty())
            {
                st.pop();
                if (!st.empty())
                    // calculate the length of the RBS ending at this closing bracket
                    max_len = max(max_len, i - st.top());
                else
                    // if stack is empty after popping, push the index of the closing bracket
                    st.push(i);
            }
            else
                // if no opening bracket to match the current closing bracket
                st.push(i);
        }
    }

    return max_len;
}

int main()
{
    string s = ")(";
    cout << "Length of longest RBS: " << findLongestRBS(s) << endl;
    return 0;
}