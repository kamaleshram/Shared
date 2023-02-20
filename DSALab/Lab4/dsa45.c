#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b) {
  if (b == 0)
    return a;
  else {
    return GCD(b, a % b);
  }
}

int findGCoPrime(int a, int b) {
  int gcd = GCD(a, b);
  while (gcd != 1) {
    a /= gcd;
    gcd = GCD(a, b);
  }

  return a;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int result = findGCoPrime(a, b);
  printf("%d", result);
}