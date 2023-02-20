#include <stdio.h>
#include <stdlib.h>

typedef struct pair_t {
  int first;
  int second;
} pair;

void merge(pair arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1, n2 = r - m;
  pair L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }

  for (int j = 0; j < n1; j++) {
    R[j] = arr[m + 1 + j];
  }

  i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if ((L[i].first <= R[j].first) ||
        ((L[i].first == R[j].first) && (L[i].second <= R[j].second))) {
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

void mergeSort(pair arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int mergeSlots(pair arr[], pair newarr[], int n) {
  newarr[0] = arr[0];
  int mergecount = 0;
  for (int i = 1, j = 1; i < n; i++) {
    if (arr[i].first > arr[i - 1].second)
      newarr[j++] = arr[i];

    else if (arr[i].first <= arr[i - 1].second) {
      newarr[j - 1].second = arr[i].second;
      mergecount++;
    }
  }

  return n - mergecount;
}

int main() {
  int n;
  scanf("%d", &n);
  pair slots[n], newslots[n];
  for (int i = 0; i < n; i++)
    scanf("%d %d", &slots[i].first, &slots[i].second);

  mergeSort(slots, 0, n - 1);

  int newn = mergeSlots(slots, newslots, n);

  printf("%d\n", newn);
  for (int i = 0; i < newn; i++)
    printf("%d %d\n", newslots[i].first, newslots[i].second);
}