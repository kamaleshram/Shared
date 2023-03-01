#include <stdio.h>

int findTeamsN(int arr[], int n, int k, int t) {
  int count = 0, sum = 0;
  for (int i = 0; i < k; i++) {
    sum += arr[i];
  }
  if (sum / k >= t)
    count++;
  for (int i = 1; i < n; i++) {
    if (i + k > n)
      break;
    sum -= arr[i - 1];
    sum += arr[i + k - 1];
    if (sum / k >= t)
      count++;
  }

  return count;
}

int main() {
  int n, k, t;
  scanf("%d %d %d", &n, &k, &t);
  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int result = findTeamsN(arr, n, k, t);
  printf("%d", result);
}