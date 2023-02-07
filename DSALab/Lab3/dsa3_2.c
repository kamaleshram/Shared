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

int search(Node *cursng, Node *temp) {
  Node *searcher = cursng;
  while (searcher != NULL) {
    if (searcher == temp) {
      return 0;
    }
    searcher = searcher->prev;
  }

  searcher = cursng;
  while (searcher != NULL) {
    if (searcher == temp) {
      return 1;
    }
    searcher = searcher->next;
  }
  return 2;
}

Node *swap_p(Node *head, Node *temp) {
  Node *tempp = temp->prev, *tempn = temp->next;
  if (tempp != NULL) {
    if (tempp == head)
      head = temp;
    Node *tempp2 = tempp->prev;
    tempp->next = tempn;
    if (tempn != NULL)
      tempn->prev = tempp;

    temp->next = tempp;
    temp->prev = tempp2;
    tempp->prev = temp;

    if (tempp2 != NULL)
      tempp2->next = temp;
  }

  return head;
}

Node *swap_n(Node *head, Node *temp) {
  Node *tempp = temp->prev, *tempn = temp->next;
  if (tempn != NULL) {
    if (temp == head)
      head = tempn;
    Node *tempn2 = tempn->next;
    temp->next = tempn2;
    if (tempn2 != NULL)
      tempn2->prev = temp;

    tempn->next = temp;
    tempn->prev = tempp;

    if (tempp != NULL)
      tempp->next = tempn;
    temp->prev = tempn;
  }
  return head;
}

void rearrange(Node *head, Node *cursng, Node *temp) {
  int pos = search(cursng, temp);
  if (pos == 1) {
    while (cursng->next != temp)
      head = swap_p(head, temp);
  }

  else if (pos == 0) {
    while (cursng->next != temp) {
      head = swap_n(head, temp);
    }
  }
}

void playNext(Node *head, Node *cursng, int song) {
  Node *temp = head;
  while ((temp != NULL) && (temp->data != song)) {
    temp = temp->next;
  }
  if (temp == NULL) {
    addToList(head, song);
    temp = head;
    while (temp->data != song) {
      temp = temp->next;
    }
  }
  rearrange(head, cursng, temp);
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

    case 6: {
      int song;
      scanf("%d", &song);
      playNext(head, cursng, song);
      break;
    }
    default:
      printf("Not a valid input!!!");
    }
    scanf("%d", &ip);
  }
}

int main() {
  Node *head = readList();
  songops(head);
  Node *temp = head;
  printList(head);
  freeList(head);
}