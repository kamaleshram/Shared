#include <stdio.h>
#include <string.h>

int main() {
  int n, k, sum = 0;
  scanf("%d %d", &n, &k);
  int arr[n], freq[k];
  memset(freq, 0, sizeof(freq));

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sum += x;
    arr[i] = x;
    freq[sum % k]++;
  }

  int ans = freq[0];

  for (int i = 1; i < k; i++)
    if (freq[i] >= 2)
      ans += (freq[i] * (freq[i] - 1)) / 2;

  printf("%d", ans);
}