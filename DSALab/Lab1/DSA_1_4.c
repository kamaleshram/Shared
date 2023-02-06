#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of values in the array: ");
  scanf("%d", &n);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if ((a[j + 1] < 0) && (a[j] > 0)) {
        a[j] = a[j] + a[j + 1];
        a[j + 1] = a[j] - a[j + 1];
        a[j] = a[j] - a[j + 1];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d\t", (a[i]));
  }

  return 0;
}