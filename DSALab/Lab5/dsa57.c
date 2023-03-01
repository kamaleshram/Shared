#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b) { return (a <= b) ? a : b; }

int maximum(int a, int b) { return (a >= b) ? a : b; }

int minFairness(int buckets[], int pieces[], int n, int currBucket,
                int maxPieces, int k) {

  if (currBucket == n) {
    return maxPieces;
  }

  int currMinFairness = 99999999;

  for (int i = 0; i < k; i++) {
    pieces[i] += buckets[currBucket];
    currMinFairness =
        minimum(currMinFairness, minFairness(buckets, pieces, n, currBucket + 1,
                                             maximum(maxPieces, pieces[i]), k));
    pieces[i] -= buckets[currBucket];
  }

  return currMinFairness;
}

int main() {

  int n, k;
  scanf("%d %d", &n, &k);
  int buckets[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &buckets[i]);
  }

  int *pieces = (int *)calloc(k, sizeof(int));

  printf("%d\n", minFairness(buckets, pieces, n, 0, 0, k));

  free(pieces);
  return 0;
}