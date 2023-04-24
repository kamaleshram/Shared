#include <iostream>
#include <vector>
using namespace std;

void pancakeSort(vector<int>& arr, vector<int>& flips) {
    int n = arr.size();
    for (int i = n; i > 1; i--) {
        int max_idx = 0;
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[max_idx])
                max_idx = j;

        // If max element is already at the right position, no need to flip
        if (max_idx == i - 1)
            continue;

        // Flip the max element to the beginning
        if (max_idx != 0) {
            flips.push_back(max_idx + 1); // k value for flip
            reverse(arr.begin(), arr.begin() + max_idx + 1);
        }
        // Flip the max element to the end
        flips.push_back(i); // k value for flip
        reverse(arr.begin(), arr.begin() + i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> flips;
    pancakeSort(arr, flips);

    int m = flips.size();

    cout << m << endl;

    for (int i = 0; i < m; i++)
        cout << flips[i] << " ";

    cout << endl;

    return 0;
}
