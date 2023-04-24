#include <bits/stdc++.h>
using namespace std;

int kth_smallest(vector<vector<int>>& matrix, int n, int k) {
    int low = matrix[0][0];
    int high = matrix[n-1][n-1];

    while (low < high) {
        int mid = (low + high) / 2;
        int count = 0, j = 0;
        
        for (int i = 0; i < n; i++) {
            while (j < n && matrix[i][j] <= mid) {
                j++;
            }
            count += j;
        }
        
        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
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

    int kth = kth_smallest(matrix, n, k);
    cout << kth << endl;

    return 0;
}
