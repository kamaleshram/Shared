#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node_t {
  int data;
  struct Node_t *next;
};
typedef struct Node_t Node;

// 2-3 // 1->3; 2->4; 3->2;
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value) {
  Node *newNode = malloc(sizeof(Node));
  assert(newNode != NULL);
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val) {
  Node *newNode = createNode(val);
  if (head == NULL) {
    return newNode;
  }
  Node *cur = head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = newNode;
  return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList() {
  int n;
  scanf("%d", &n);
  Node *head = NULL;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (head == NULL) {
      head = addToList(head, x);
    } else {
      addToList(head, x);
    }
  }
  return head;
}

// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head) {
  Node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
  return;
}

// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head) {
  Node *cur, *nxt;
  cur = head;
  while (cur != NULL) {
    nxt = cur->next;
    free(cur);
    cur = nxt;
  }
}

int getSize(Node *head) {
  Node *tmp = head;
  int n = 0;
  while (tmp != NULL) {
    n++;
    tmp = tmp->next;
  }
  return n;
}

int findMedian(Node *head) {
  int n = getSize(head);

  Node *temp = head;
  if (n % 2 != 0) {
    for (int i = 1; i < ((n + 1) / 2); i++) {
      temp = temp->next;
    }

    return temp->data;
  }

  else if (n % 2 == 0) {
    int n1, n2;
    for (int i = 1; i < (n / 2); i++) {
      temp = temp->next;
    }

    n1 = temp->data;
    n2 = temp->next->data;

    return (n1 + n2) / 2;
  }

  return 0;
}
// Function definition goes here
int main(void) {
  Node *head = readList();
  int median = findMedian(head);
  printf("%d\n", median);
  freeList(head);
  return 0;
}