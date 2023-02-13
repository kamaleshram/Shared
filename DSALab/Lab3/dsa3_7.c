#include <stdio.h>

int getDeduct(int arr[], int s, int e, int target) {
  int mid = (s + e) / 2;

  if (s == mid) {
    if (arr[e] <= target)
      return arr[e];
    else
      return arr[s];
  }

  if (arr[mid] < target) {
    return getDeduct(arr, mid, e, target);
  }

  if (arr[mid] >= target) {
    return getDeduct(arr, s, mid, target);
  }

  return -1;
}

int main() {
  int n, target, answer;
  scanf("%d %d", &n, &target);
  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  answer = getDeduct(arr, 0, n - 1, target);
  printf("%d", answer);
}