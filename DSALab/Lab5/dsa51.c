#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

void generate_sequences_helper(char *sequence, int num_open, int num_closed,
                               int n);

void generate_regular_bracket_sequences(int n) {
  char *sequence = (char *)malloc((n + 1) * sizeof(char));
  sequence[n] = '\0';
  generate_sequences_helper(sequence, 0, 0, n);
  free(sequence);
}

void generate_sequences_helper(char *sequence, int num_open, int num_closed,
                               int n) {
  if (num_open + num_closed == n) {
    if (num_open == num_closed) {
      printf("%s\n", sequence);
    }
    return;
  }

  if (num_open < n / 2) {
    sequence[num_open + num_closed] = '(';
    generate_sequences_helper(sequence, num_open + 1, num_closed, n);
  }

  if (num_closed < num_open) {
    sequence[num_open + num_closed] = ')';
    generate_sequences_helper(sequence, num_open, num_closed + 1, n);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", ((factorial(n) / (factorial(n / 2) * factorial(n / 2))) /
                  ((n / 2) + 1)));
  generate_regular_bracket_sequences(n);
  return 0;
}
