#include <stdio.h>

#define int long long int

int main() {

  int inputLength, noOfOddNeeded;
  scanf("%lld %lld", &inputLength, &noOfOddNeeded);

  int input[inputLength];

  // We count the number of odd numbers
  int noOfOdds = 0;
  for (int i = 0; i < inputLength; i++) {
    scanf("%lld", &input[i]);

    if (input[i] % 2 == 1)
      noOfOdds++;
  }

  // We keep track of odd indices
  int oddIndices[noOfOdds], c = 0;
  for (int i = 0; i < inputLength; i++) {
    // Then we keep track of where odd numbers are there
    if (input[i] % 2 == 1) {
      oddIndices[c] = i;
      // c is used to change the indices of the array of oddIndices
      c++;
    }
  }

  // Empty array to keep track of answer
  int answer = 0;

  for (int i = 0; i < noOfOdds - noOfOddNeeded + 1; i++) {
    int leftIndex = i;
    int rightIndex = i + noOfOddNeeded - 1;

    int left = oddIndices[leftIndex];
    int right = oddIndices[rightIndex];

    int leftcounter = 1;
    int rightcounter = 1;

    if (leftIndex == 0) {
      leftcounter = oddIndices[leftIndex] + 1;
    } else {
      leftcounter = oddIndices[leftIndex] - oddIndices[leftIndex - 1];
    }

    if (rightIndex == noOfOdds - 1) {
      rightcounter = inputLength - oddIndices[rightIndex];
    } else {
      rightcounter = oddIndices[rightIndex + 1] - oddIndices[rightIndex];
    }

    answer += (leftcounter * rightcounter);
  }

  printf("\n%lld", answer);
}