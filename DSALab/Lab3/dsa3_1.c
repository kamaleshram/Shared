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

void songops(Node *head) {
  Node *cursng = head;
  int ip;
  scanf("%d", &ip);
  while (ip != 5) {
    switch (ip) {
    case 1: {
      int song;
      scanf("%d", &song);
      addToList(head, song);
      break;
    }
    case 2: {
      if (cursng != NULL) {
        printf("\n%d\n", cursng->data);
      }

      else {
        printf("No songs available\n");
      }
      break;
    }
    case 3: {
      if (cursng->next == NULL) {
        break;
      } else {
        cursng = cursng->next;
        break;
      }
    }
    case 4: {
      if (cursng->prev == NULL) {
        break;
      } else {
        cursng = cursng->prev;
        break;
      }
    }
    }
    scanf("%d", &ip);
  }
}

int main() {
  Node *head = readList();
  songops(head);
  freeList(head);
}