#include <bits/stdc++.h> 
using namespace std;

int ksmallest(vector<vector<int>> mat, int n, int k) {
    int low = mat[0][0];
    int high = mat[n-1][n-1];

    while (low < high) {
        int mid = (low + high) / 2;
        int count = 0, j = n-1;

        for (int i = 0; i < n; i++) {
            while (j >= 0 and mat[i][j] > mid)
                j--;
            count += j + 1;
        }

        if (count < k)
            low = mid+1;
        else
            high = mid;
    }

    return low;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << ksmallest(matrix, n, k) << endl;

    return 0;
}