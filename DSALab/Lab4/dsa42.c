#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1, n2 = r - m;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }

  for (int j = 0; j < n1; j++) {
    R[j] = arr[m + 1 + j];
  }

  i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    }

    else
      arr[k++] = R[j++];
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }

  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int check(int arr[], int a, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[n - i - 1] >= a)
      count++;
  }
  if (count == a)
    return 1;
  else
    return 0;
}

int findScore(int arr[], int n) {
  int max;
  if (arr[0] >= n)
    return n;

  max = arr[n - 1];
  for (int i = 0; i < n; i++) {
    if (check(arr, arr[i], n) == 1)
      max = arr[i];
  }
  return max;
}

int main() {
  int n;
  scanf("%d", &n);

  int dogdays[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &dogdays[i]);

  mergeSort(dogdays, 0, n - 1);
  int score = findScore(dogdays, n);
  printf("%d", score);
}