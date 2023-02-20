#include <stdio.h>
#include <stdlib.h>

int findZeroes(int a) {
  if (a == 0)
    return 0;
  return a / 5 + findZeroes(a / 5);
}

int countPairs(int arr[], int n) {
  int max = arr[0], count = 0;
  for (int i = 0; i < n; i++) {
    if (max < arr[i])
      max = arr[i];
  }

  int trailingzeroes[n];
  for (int i = 0; i < n; i++) {
    trailingzeroes[i] = findZeroes(arr[i]);
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (trailingzeroes[i] == trailingzeroes[j]) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int n;
  scanf("%d", &n);

  int list[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &list[i]);

  int pairs = countPairs(list, n);

  printf("%d", pairs);
}
