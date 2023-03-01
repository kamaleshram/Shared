#include <stdio.h>

int survivor(int n, int lefttoright) {
  if (n == 1)
    return 1;

  if (lefttoright == 1)
    return 2 * survivor(n / 2, 0);

  if (n % 2 == 0)
    return 2 * survivor((n + 1) / 2, 1) - 1;

  return 2 * survivor(n / 2, 1);
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d", survivor(n, 1));
}