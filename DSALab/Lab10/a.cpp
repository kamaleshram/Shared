#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n) {
	int maxsofar = INT_MIN, maxendinghere = 0;
	for (int i = 0; i < n; i++) {
		maxendinghere += a[i];

		maxsofar = max(maxsofar, maxendinghere);

		if (maxendinghere < 0)
			maxendinghere = 0; 
	}

	return maxsofar;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	
	for (int i = 0; i < n; i++)
	    cin >> a[i];
	
	cout << maxSubArraySum(a, n) << endl;
	return 0;
}
