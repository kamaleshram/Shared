#include <stdio.h>

typedef struct olympcont_t {
  char ctryname[20];
  int gold;
  int silver;
  int bronze;
} country;

void readcarray(country carray[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%s", carray[i].ctryname);
    scanf("%d", &(carray[i].gold));
    scanf("%d", &(carray[i].silver));
    scanf("%d", &(carray[i].bronze));
  }
}

void swap(country *c1, country *c2) {
  country temp = *c1;
  *c1 = *c2;
  *c2 = temp;
}

void sortctries(country carray[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (carray[j].gold < carray[j + 1].gold)
        swap(&carray[j], &carray[j + 1]);

      else if (carray[j].gold == carray[j + 1].gold) {
        if (carray[j].silver < carray[j + 1].silver)
          swap(&carray[j], &carray[j + 1]);
      } else if (carray[j].silver == carray[j + 1].silver) {
        if (carray[j].bronze < carray[j + 1].bronze)
          swap(&carray[j], &carray[j + 1]);
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  country carray[n];
  readcarray(carray, n);
  sortctries(carray, n);
  for (int i = 0; i < n; i++) {
    printf("%s\n", carray[i].ctryname);
  }
  return 0;
}