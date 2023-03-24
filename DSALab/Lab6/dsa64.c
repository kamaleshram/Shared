#include <stdio.h>

#define MAXN 100005

int n, a[MAXN], counts[MAXN], firstNonRepeating[MAXN], stack[MAXN], top = -1;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    counts[a[i]]++;

    while (top >= 0 && counts[a[stack[top]]] > 1) {
      top--;
    }

    if (top < 0) {
      firstNonRepeating[i] = a[i];
    } else {
      firstNonRepeating[i] = a[stack[top]];
    }

    top++;
    stack[top] = i;
  }

  for (int i = 1; i <= n; i++) {
    printf("%d ", firstNonRepeating[i]);
  }
  printf("\n");

  return 0;
}
