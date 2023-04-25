#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    ll inv_count = 0;

    i = left; // index for left subarray
    j = mid; // index for right subarray
    k = left; // index for temp array

    while((i <= mid - 1) && (j <= right)) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

ll merge_sort(int arr[], int temp[], int left, int right) {
    ll inv_count = 0;
    int mid;

    if(right > left) {
        mid = (left + right) / 2;
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }

    return inv_count;
}

ll inversion_count(int arr[], int n) {
    int temp[n];
    return merge_sort(arr, temp, 0, n-1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << inversion_count(arr, n) << endl;
    return 0;
}
