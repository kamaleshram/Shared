#include <stdio.h>
#include <stdlib.h>

int findPlanks(int a[], int n, int mid) {
  if (mid == 0)
    return 0;

  int count = 0;
  for (int i = 0; i < n; i++) {
    int temp = a[i];
    while (temp >= mid) {
      count++;
      temp -= mid;
    }
  }

  return count;
}

int findGreatestSize(int a[], int n, int lb, int ub, int reqplanks) {
  int mid = (lb + ub) / 2, count;
  if (ub < lb) {
    int count = findPlanks(a, n, ub);
    if (count >= reqplanks)
      return ub;

    else
      return 0;
  }

  count = findPlanks(a, n, mid);
  if (count < reqplanks) {
    return findGreatestSize(a, n, lb, mid - 1, reqplanks);
  }

  else if (count >= reqplanks) {
    return findGreatestSize(a, n, mid + 1, ub, reqplanks);
  }

  return -1;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sortD(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] < a[j + 1])
        swap(&a[j], &a[j + 1]);
    }
  }
}

int main() {
  int n, planks, greatestSize;
  scanf("%d %d", &n, &planks);
  int a[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sortD(a, n);
  int lb = 1, ub = a[0];
  greatestSize = findGreatestSize(a, n, lb, ub, planks);
  printf("%d", greatestSize);
}