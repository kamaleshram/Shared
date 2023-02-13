#include <stdio.h>

int getStepRev(long int s, long int e, long int n, long int targsum) {
  long int mid = (s + e) / 2;

  if (s == mid) {
    if (targsum < (n * (n + 1) - (s * (s + 1)) / 2))
      return n - e + 1;
    else
      return n - s + 1;
  }

  if (targsum < (((n * (n + 1)) - (mid * (mid + 1))) / 2)) {
    return getStepRev(mid, e, n, targsum);
  } else if (targsum > (((n * (n + 1)) - (mid * (mid + 1))) / 2)) {
    return getStepRev(s, mid, n, targsum);
  }
  return -1;
}

int main() {
  long int n;
  scanf("%ld", &n);
  long int targsum = (n * (n - 1)) / 4;
  int result = getStepRev(1, n - 1, n - 1, targsum);
  printf("%d", result);
}