#include <stdio.h>
#include <stdlib.h>

typedef struct pair_t {
  int cand;
  int freq;
} pair;

void findWinners(int votes[], int n, int winners[], int a) {
  pair *vote = (pair *)calloc(n, sizeof(pair));

  for (int i = 0; i < n; i++) {
    vote[i].cand = i + 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (votes[j] == i + 1) {
        vote[i].freq++;
      }
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vote[j].freq < vote[j + 1].freq) {
        pair temp = vote[j];
        vote[j] = vote[j + 1];
        vote[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < a; i++)
    winners[i] = vote[i].cand;
}

int main() {
  int n, a;
  scanf("%d %d", &n, &a);
  int votes[n], winners[a];

  for (int i = 0; i < n; i++)
    scanf("%d", &votes[i]);

  findWinners(votes, n, winners, a);

  for (int i = 0; i < a; i++) {
    printf("%d ", winners[i]);
  }
}