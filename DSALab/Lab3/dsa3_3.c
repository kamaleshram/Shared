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

Node *readList() {
  int n;
  scanf("%d", &n);
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

int dyadag(Node *head, int target) {
  Node *tempn = head;
  Node *tempp = head;
  while (tempp->next != NULL)
    tempp = tempp->next;
  while (tempn != tempp) {
    if (tempn->data + tempp->data == target)
      return 1;
    else if (tempn->data + tempp->data < target)
      tempn = tempn->next;
    else if (tempn->data + tempp->data > target)
      tempp = tempp->prev;
  }
  return 0;
}

int main() {
  int target;
  scanf("%d", &target);
  Node *head = readList();
  int result = dyadag(head, target);
  printf("%d\n", result);
}