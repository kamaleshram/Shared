#include <stdio.h>

int sqRt(long int i, long int n, long int target) {
  long int mid = (n + i) / 2;

  if (i == mid) {
    return mid;
  }

  if (mid * mid > target)
    return sqRt(i, mid, target);

  else if (mid * mid <= target)
    return sqRt(mid, n, target);

  return -1;
}

int main() {
  long int n;
  scanf("%ld", &n);

  long int result = sqRt(1, n, n);
  printf("%ld", result);
}