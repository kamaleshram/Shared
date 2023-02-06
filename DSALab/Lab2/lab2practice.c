#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
  int data;
  struct Node_t *next;
} Node;

Node *createNode(int val) {
  Node *newNode = malloc(sizeof(Node));
  assert(newNode != NULL);
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

Node *addToList(Node *head, int val) {
  Node *newNode = createNode(val);
  if (head == NULL) {
    return newNode;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
  }
}

Node *readList() {
  int n;
  scanf("%d", &n);
  Node *head = NULL;

  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    if (head == NULL)
      head = addToList(head, val);
    else
      addToList(head, val);
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
  while (temp != NULL) {
    next = temp->next;
    free(temp);
    temp = next;
  }
}

int getSize(Node *head) {
  Node *temp = head;
  int n = 0;
  while (temp != NULL) {
    n++;
    temp = temp->next;
  }
  return n;
}

int main() {}