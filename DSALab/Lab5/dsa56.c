#include <stdio.h>

int findXOR(int A[], int B[], int n, int m) {
  int xsum = 0;
  if ((n % 2 == 0) && (m % 2 != 0)) {
    for (int i = 0; i < n; i++) {
      xsum ^= A[i];
    }
  }

  if ((n % 2 != 0) && (m % 2 == 0)) {
    for (int i = 0; i < n; i++) {
      xsum ^= A[i];
    }
  }

  if ((n % 2 != 0) && (m % 2 != 0)) {
    for (int i = 0; i < n; i++) {
      xsum ^= A[i];
    }
    for (int i = 0; i < m; i++) {
      xsum ^= B[i];
    }
  }

  return xsum;
}

int main() {
  int n, m;
  scanf("%d", &n);
  int A[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  scanf("%d", &m);
  int B[m];

  for (int j = 0; j < m; j++) {
    scanf("%d", &B[j]);
  }

  int result = findXOR(A, B, n, m);
  printf("%d", result);
}