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

Node *delNode(Node *head, Node *temp) {
  if (temp == NULL)
    return head;

  else if (temp == head) {
    head = head->next;
    if (head != NULL)
      head->prev = NULL;
    // free(temp);
  }

  else {
    Node *tempp = temp->prev;
    Node *tempn = temp->next;
    if (tempp != NULL)
      tempp->next = tempn;
    if (tempn != NULL)
      tempn->prev = tempp;
    temp->next = NULL;
    temp->prev = NULL;
    // free(temp);
  }

  return head;
}

int *formTeams(Node *head) {
  int *teamsum = (int *)malloc(2 * sizeof(int));
  int *teamsumfr = (int *)calloc(2, sizeof(int));
  int *teams = (int *)malloc(2 * sizeof(int));
  int *teamsfr = (int *)calloc(2, sizeof(int));

  Node *tempn = head, *tempp = head;

  while (tempp->next != NULL)
    tempp = tempp->next;

  teamsum[0] = tempn->data;
  teams[0]++;
  teamsum[1] = tempp->data;
  teams[1]++;
  Node *deltempn = tempn;
  Node *deltempp = tempp;

  if (tempn != NULL)
    tempn = tempn->next;
  if (tempp != NULL)
    tempp = tempp->prev;

  head = delNode(head, deltempn);
  head = delNode(head, deltempp);

  while (((tempp != NULL) || (tempn != NULL)) && (tempp != tempn)) {
    if (((tempn != NULL)) && (teamsum[0] < teamsum[1])) {
      teamsum[0] += tempn->data;
      teams[0]++;
      Node *deltempn = tempn;
      tempn = tempn->next;
      head = delNode(head, deltempn);
    }

    else if (((tempp != NULL)) && (teamsum[0] > teamsum[1])) {
      teamsum[1] += tempp->data;
      teams[1]++;
      Node *deltempp = tempp;
      tempp = tempp->prev;
      head = delNode(head, deltempp);
    }

    else if (teamsum[0] == teamsum[1]) {
      teamsfr[0] = teams[0];
      teamsfr[1] = teams[1];

      teams[0]++;
      teams[1]++;

      Node *deltempn = tempn;
      Node *deltempp = tempp;

      if (tempn != NULL) {
        teamsum[0] += tempn->data;
        tempn = tempn->next;
      }

      if (tempp != NULL) {
        teamsum[1] += tempp->data;
        tempp = tempp->prev;
      }

      head = delNode(head, deltempn);
      head = delNode(head, deltempp);
    }
  }

  if ((tempp != NULL) && (tempn != NULL) && (teamsum[0] == teamsum[1])) {
    teamsfr[0] = teams[0];
    teamsfr[1] = teams[1];
  }
  return teamsfr;
}

int main() {
  Node *head = readList();
  int *teams;
  teams = formTeams(head);
  printf("%d %d", teams[0], teams[1]);
  free(teams);
}