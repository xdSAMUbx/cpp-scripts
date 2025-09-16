// This code will try to make a link list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

node *initial(int *data){
  node *res = malloc(sizeof *res);
  res->value = *data;
  res->next = NULL;
  return res;
}

void addInit(node *head, int *data){
  node *newNode = malloc(sizeof *newNode);
  newNode->value = *data;
  head->next = newNode;
  newNode->next = NULL;
}

void addLast(node *head, int *data){
  node *newNode = malloc(sizeof *newNode);
  newNode->value = *data;
  newNode->next = NULL; 
  // Recorre hasta llegar al penultimo
  node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void addAt(node *head, int *pos, int *data){
  node *newNode = malloc(sizeof *newNode);
  newNode->value = *data;
  newNode->next = NULL;

  node *temp = head;
  for (int i = 0; i < *pos; i++){
    temp = temp->next;
  }

  if (temp == NULL){
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

// ** Pasa la dirección del puntero 
void deleteat(node **head, int *pos){
  if (*pos == 0){
    node *del = *head;
    *head = del->next;
    free(del);
  }

  node *prev = *head;
  for (int i = 0; i < *pos - 1 && prev->next !=NULL; i++){
    prev = prev->next;
  }

  node *del = prev->next;
  prev->next = del->next;
  free(del);
}

int main(){
  int n = 5, n1 = 2, n2 = 3;
  node *head = initial(&n);
  addInit(head, &n1);
  addLast(head, &n2);
  node *sig = head;
  while(sig != NULL){
    printf("%d ", sig->value);
    sig = sig->next;
  }
  printf("\n");
  
  return 0;
}
