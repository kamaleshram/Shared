#include <stdio.h>

int checkAlphabets(int arr[], int k) {

  for (int i = 0; i < k; i++) {
    if (arr[i] == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {

  int n;
  scanf("%d", &n);

  int k;
  scanf("%d", &k);

  char str[n + 1];
  scanf("%s", str);

  int arr[k];

  for (int i = 0; i < k; i++) {

    arr[i] = 0;
  }

  int i = 0;
  int j = 0;
  arr[str[i] - 'a']++;
  int count = 0;

  while (j < n) {
    if (checkAlphabets(arr, k) == 1) {
      arr[str[i] - 'a']--;
      i++;
      count += (n - j);
    } else {
      j++;
      if (j == n)
        break;
      arr[str[j] - 'a']++;
    }
  }

  printf("%d", count);
}