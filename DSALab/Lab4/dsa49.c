#include <stdio.h>

int getGCD(int a, int b) {
  if (b == 0)
    return a;
  else
    return getGCD(b, a % b);
}

int getGCDArr(int arr[], int n) {
  int gcd = arr[0];
  for (int i = 1; i < n; i++) {
    gcd = getGCD(gcd, arr[i]);
  }

  return gcd;
}

int getNewGcd(int arr[], int n) {
  int gcdarr[n];
  for (int i = 0; i < n; i++) {
    int newarr[n - 1], flag = 0;
    for (int j = 0, k = 0; j < n - 1; j++, k++) {
      if ((i == j) && (flag == 0)) {
        j--;
        flag = 1;
        continue;
      } else
        newarr[j] = arr[k];
    }

    gcdarr[i] = getGCDArr(newarr, n);
  }

  int max = gcdarr[0];
  for (int i = 0; i < n; i++) {
    if (max < gcdarr[i])
      max = gcdarr[i];
  }
  return max;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int newgcd = getNewGcd(arr, n);
  printf("%d", newgcd);
}