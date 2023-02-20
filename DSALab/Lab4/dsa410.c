#include <stdio.h>

int getCount(int arr[], int n) {
  int sum = 0, avg, count = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  avg = sum / n;

  for (int i = 0; i < n; i++) {
    while (arr[i] != avg) {
      if (arr[i] > avg) {
        arr[i]--;
        count++;
      } else {
        arr[i]++;
        count++;
      }
    }
  }

  return count;
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int count = getCount(arr, n);
  printf("%d", count);
}