#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_dll {
  int data;
  struct Node_dll *next;
  struct Node_dll *prev;
} Node;

Node *createNode(int val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  assert(newNode != NULL);
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

Node *addToList(Node *head, int val) {
  Node *newNode = createNode(val);

  if (head == NULL) {
    return newNode;
  }

  else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
  return newNode;
}

Node *readListnDays(int *p) {
  int n;
  scanf("%d", &n);
  scanf("%d", p);
  Node *head = NULL;
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    if (head == NULL) {
      head = addToList(head, val);
    } else {
      addToList(head, val);
    }
  }
  return head;
}

void printList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  return;
}

void freeList(Node *head) {
  Node *temp = head, *next;
  while (temp->next != NULL) {
    next = temp->next;
    free(temp);
    temp = next;
  }
  return;
}

Node *rotateList(Node *head, int days) {
  Node *temp = head;
  Node *tempp = head;
  while (tempp->next != NULL)
    tempp = tempp->next;

  tempp->next = temp;
  temp->prev = tempp;

  for (int i = 0; i < days; i++) {
    head = head->prev;
  }

  Node *headp = head->prev;
  head->prev = NULL;
  headp->next = NULL;

  return head;
}

int main() {
  int days;
  int *p = &days;
  Node *head = readListnDays(p);
  head = rotateList(head, days);
  printList(head);
  freeList(head);
}