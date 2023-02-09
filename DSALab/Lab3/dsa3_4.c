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

Node *delNode(Node *temp) { return temp; }

int *formTeams(Node *head) {
  int *teamsum = (int *)malloc(2 * sizeof(int));
  int *teamsumfr = (int *)calloc(2, sizeof(int));
  Node *tempn = head, *tempp = head;

  while (tempp->next != NULL)
    tempp = tempp->next;

  teamsum[0] = tempn->data;
  tempn = tempn->next;
  teamsum[1] = tempp->data;
  tempp = tempp->prev;

  while (((tempp != NULL) || (tempn != NULL)) && (tempp->next != tempn->prev)) {
    if (teamsum[0] < teamsum[1]) {
      teamsum[0] += tempn->data;
      tempn = tempn->next;
    }

    else if (teamsum[0] > teamsum[1]) {
      teamsum[1] += tempp->data;
      tempp = tempp->prev;
    }

    else if (teamsum[0] == teamsum[1]) {
      printf("Inside\n");
      printf("%d\n", tempn->data);
      printf("%d\n", tempp->data);
      teamsumfr[0] = teamsum[0];
      teamsumfr[1] = teamsum[1];
      teamsum[0] += tempn->data;
      teamsum[1] += tempp->data;
      tempn = tempn->next;
      tempp = tempp->prev;
    }
  }
  return teamsumfr;
}

int main() {
  Node *head = readList();
  int *teams;
  teams = formTeams(head);
  printf("%d %d", teams[0], teams[1]);
  freeList(head);
  free(teams);
}