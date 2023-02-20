#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int primeSieve(int n) {
  int count = 0;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }

  // Print all prime numbers
  for (int p = 2; p <= n; p++)
    if (prime[p])
      count++;

  return count;
}

void findPrimes(int list[], int primes[], int q, int n) {
  for (int i = 0; i < q; i++) {
    if (list[i] < n) {
      primes[i] = primeSieve(list[i]);
    }

    else
      primes[i] = 0;
  }
}

// Driver Code
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int list[q], primes[q];
  for (int i = 0; i < q; i++) {
    scanf("%d", &list[i]);
  }

  findPrimes(list, primes, q, n);
  for (int i = 0; i < q; i++) {
    printf("%d ", primes[i]);
  }
}

// This code is contributed by Aditya Kumar (adityakumar129)
