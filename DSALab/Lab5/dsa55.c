#include <stdio.h>

int main() {
  int n, k, zeroes = 0, ans = 0;
  scanf("%d %d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      zeroes++;
    }
  }

  if (k >= zeroes) {
    ans = n;
  } else {
    int lo = 0;
    int hi = 0;
    int no = 1 - a[hi];

    while (lo <= hi && hi < n) {
      if (no < k) {
        hi++;
        if (a[hi] == 0) {
          no++;
        }
      } else if (no == k) {
        if (hi - lo + 1 > ans) {
          ans = hi - lo + 1;
        }
        while (no != k + 1 && hi < n) {
          hi++;
          if (hi < n) {
            if (a[hi] == 0) {
              no++;
              if (hi - lo > ans) {
                ans = hi - lo;
              }
            } else {
              if (hi - lo + 1 > ans) {
                ans = hi - lo + 1;
              }
            }
          }
        }
      } else {
        if (a[lo] == 0) {
          lo++;
          no--;
        } else {
          lo++;
        }
      }
    }
  }
  printf("%d", ans);
}