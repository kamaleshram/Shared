#include <iostream>
#include <vector>
using namespace std;

int max_length_subarray(vector<int> &a, vector<int> &b)
{
    // Initialize the table with zeros
    int n = a.size(), m = b.size();
    vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));
    int max_length = 0;

    // Fill in the table using the recurrence relation
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                max_length = max(max_length, table[i][j]);
            }
        }
    }

    // Return the final solution
    return max_length;
}

int main()
{
    vector<int> a = {1};
    vector<int> b = {3, 2, 1, 4, 7, -4};
    cout << max_length_subarray(a, b) << endl; // Output: 3
    return 0;
}