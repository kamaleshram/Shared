#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], freq[100001] = {0}, ans[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
        ans[i] = -1; // initialize ans array with -1
        for(int j = 0; j <= i; j++) {
            if(freq[a[j]] == 1) {
                ans[j] = a[j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
