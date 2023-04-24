// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>
using namespace std;

/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int search(int m, int mat[m][], int n, int x)
{
	if (n == 0)
		return -1;

	int smallest = mat[0][0], largest = mat[m - 1][n - 1];
	if (x < smallest || x > largest)
		return -1;

	// set indexes for top right element
	int i = 0, j = n - 1;
	while (i < n && j >= 0) {
		if (mat[i][j] == x) {
			cout << "Element found at " << i << ", " << j;
			return 1;
		}
		if (mat[i][j] > x)
			j--;

		// Check if mat[i][j] < x
		else
			i++;
	}

	cout << "n Element not found";
	return 0;
}

// Driver code
int main()
{
	int m, n;
    cin >> m >> n;
    int mat[m][n];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    }

    int val;
    cin >> val;

	// Function call
	search(m, mat, n, val);

	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)
