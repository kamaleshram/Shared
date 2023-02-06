#include <stdio.h>
#include <string.h>

typedef struct student_t {
  char email[40];
  char bname[5];
  char id[15];
} student;

void generateId(student *s) {
  char idyr[6], idno[6];
  for (int i = 0; i < 4; i++) {
    idyr[i] = s->email[i + 1];
  }
  strcpy(s->id, idyr);
  idyr[4] = '\0';
  strcat(s->id, "A");
  if (strcmp(s->bname, "CS") == 0)
    strcat(s->id, "7");
  if (strcmp(s->bname, "ECE") == 0)
    strcat(s->id, "A");
  if (strcmp(s->bname, "EEE") == 0)
    strcat(s->id, "3");
  strcat(s->id, "PS");
  for (int i = 0; i < 4; i++) {
    idno[i] = s->email[i + 5];
  }
  idno[4] = '\0';
  strcat(s->id, idno);
  strcat(s->id, "H");
}

int main() {
  student s1;
  char id[20];
  gets(s1.email);
  gets(s1.bname);
  generateId(&s1);
  printf("%s", s1.id);
}
