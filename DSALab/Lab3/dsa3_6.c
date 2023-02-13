#include <assert.h>
#include <stdio.h>

void distTeams(int arr[], int *count, int s, int e) {
  int mid = (s + e) / 2;
  if (s == mid) {
    return;
  }

  if ((arr[mid] != arr[s]) && (arr[mid] != arr[e])) {
    (*count)++;
    distTeams(arr, count, s, mid);
    distTeams(arr, count, mid, e);
  }

  else if ((arr[mid] == arr[s]) && (arr[mid] != arr[e])) {
    distTeams(arr, count, mid, e);
  }

  else if ((arr[mid] != arr[s]) && (arr[mid] == arr[e])) {
    distTeams(arr, count, mid, e);
  }
}

int main() {
  int n, count;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  if (arr[0] != arr[n - 1]) {
    count = 2;
    distTeams(arr, &count, 0, n - 1);
  }

  else
    count = 1;

  printf("%d", count);
}