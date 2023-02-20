#include <stdio.h>

int getMaxPairs(int kings, int halls) {
  int maxkings = kings - halls + 1;
  return (maxkings * (maxkings - 1)) / 2;
}

int getMinPairs(int kings, int halls) {
  int minn = kings / halls, rem = kings % halls, sumperm = 0;
  int arr[halls];
  for (int i = 0; i < halls; i++) {
    arr[i] = minn;
  }
  int count = 0;
  while (rem > 0) {
    arr[count++]++;
    rem--;
  }

  for (int i = 0; i < halls; i++) {
    sumperm += (arr[i] * (arr[i] - 1)) / 2;
  }

  return sumperm;
}
int main() {
  int k, b;
  scanf("%d %d", &k, &b);

  int min = getMinPairs(k, b);
  int max = getMaxPairs(k, b);

  printf("%d %d", min, max);
}