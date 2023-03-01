#include <stdio.h>
#include <time.h>

int main() {
  int n;
  long long randomnumber;
  int t = 0;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);

    t = time(NULL);
    if (((x + t) % i) == 0)
      randomnumber = x;

    printf("%lld\n", randomnumber);
  }
  return 0;
}