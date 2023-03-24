#include <stdio.h>
#include <stdlib.h>

typedef struct deque_t {
  int data;
  struct deque_t *next;
  struct deque_t *prev;
} deque;

void printQueue(deque *back) {
  deque *temp = back;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

deque *pushFront(deque *front, int val) {
  deque *node = malloc(sizeof(deque));
  node->data = val;
  node->next = NULL;
  node->prev = NULL;

  if (front == NULL) {
    return node;
  } else {
    front->next = node;
    node->prev = front;
    front = node;
    return front;
  }
}

deque *pushBack(deque *back, int val) {
  deque *node = malloc(sizeof(deque));
  node->data = val;
  node->next = NULL;
  node->prev = NULL;

  if (back == NULL) {
    return node;
  } else {
    back->prev = node;
    node->next = back;
    back = node;
    return back;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int lex[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &lex[i]);

  deque *front = NULL, *back = NULL;

  for (int i = 0; i < n; i++) {
    if (front == NULL)
      front = back = pushFront(front, lex[i]);
    else {
      if (lex[i] <= back->data)
        back = pushBack(back, lex[i]);
      else
        front = pushFront(front, lex[i]);
    }
  }

  printQueue(back);
}