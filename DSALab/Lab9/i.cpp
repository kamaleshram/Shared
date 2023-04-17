#include <bits/stdc++.h>
using namespace std;

// The function returns starting point if there is a
// possible solution, otherwise returns -1
int printTour(int a[], int b[], int n)
{
    // deficit is used to store the value of the capacity as
    // soon as the value of capacity becomes negative so as
    // not to traverse the array twice in order to get the
    // solution
    int start = 0, deficit = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++)
    {
        capacity += a[i] - b[i];
        if (capacity < 0)
        {
            // If this particular step is not done then the
            // between steps would be redundant
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int start = printTour(a, b, n);

    cout << start << endl;

    return 0;
}
