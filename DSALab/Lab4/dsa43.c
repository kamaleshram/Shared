#include <stdio.h>

int trailing_zeros(int n) {
  if (n < 0)
    return -1;

  int count = 0;

  for (int i = 5; n / i >= 1; i *= 5)
    count += n / i;

  return count;
}

int max(int num1, int num2) { return (num1 > num2) ? num1 : num2; }

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];

  int m = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    m = max(m, arr[i]);
  }

  int maxzero = trailing_zeros(m);

  if (m == 1 || maxzero == 0) {
    maxzero = n;
  }

  int zero[maxzero];

  for (int i = 0; i < maxzero; i++) {
    zero[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    zero[trailing_zeros(arr[i])]++;
  }

  int ans = 0;
  for (int i = 0; i < maxzero; i++) {
    if (zero[i] == 2)
      ans++;
    else if (zero[i] > 2) {
      int temp = zero[i];
      ans = ans + (temp) * (temp - 1) / 2;
    } else {
      continue;
    }
  }

  printf("%d", ans);
  return 0;
}