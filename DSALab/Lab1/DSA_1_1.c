#include <stdio.h>
#include <stdlib.h>
int main() {
  int **p, **q, **l, m, n, ri, ci, r, c, x;
  printf("Enter row,column,row index,column index,row and column height");
  p = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    *(p + i) = (int *)malloc(n * sizeof(int));
  }
  scanf("%d %d %d %d %d %d", &m, &n, &ri, &ci, &r, &c);
  printf("Now enter value row wise");
  for (int i = 0; i < m, i++) {
    printf("Enter", i + 1, "row");
    for (int j = 0; j < n; j++) {
      scanf("%d", &x);
      p[i][j] = x;
    }
  }
  q = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    *(q + i) = (int *)malloc(n * sizeof(int));
  }
  x = 0;
  for (int i = 0; i < m, i++) {
    for (int j = 0; j < m; j++) {
      x += p[i][j];
      q[i][j] = x;
    }
  }
  if (ri + r > m) {
    printf("Submatrix cannot be created");
  }
  if (ci + c > n) {
    printf("Submatrix cannot be created");
  }
  l = (int **)malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    *(l + i) = (int *)malloc(c * sizeof(int));
  }
  x = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      l[i][j] = q[ri + i][ci + j];
      x += l[i][j];
    }
  }
