#include <stdio.h>
#include <stdlib.h>

int getMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

void countingSort(int a[], int n, int place) {
  int output[n];
  int *count = (int *)calloc(10, sizeof(int));

  for (int i = 0; i < n; i++) {
    count[(a[i] / place) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(a[i] / place) % 10] - 1] = a[i];
    count[(a[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    a[i] = output[i];
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void radixSort(int a[], int n) {
  int max = getMax(a, n);

  for (int place = 1; max / place > 0; place *= 10) {
    countingSort(a, n, place);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  radixSort(arr, n);
}