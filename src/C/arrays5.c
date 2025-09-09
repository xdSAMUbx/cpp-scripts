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

void addInit(node *behind, int *data){
  node *newNode = malloc(sizeof *newNode);
  newNode->value = *data;
  behind->next = newNode;
  newNode->next = NULL;
}

void addLast(node *behind, int *data){
  node *newNode = malloc(sizeof *newNode);
  newNode->value = *data;
  newNode->next = NULL; 
  // Recorre hasta llegar al penultimo
  node *temp = behind;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void addAt(node *behind, int *pos, int *data){
  node *newNode = malloc(sizeof *newNode);
  newNode->value = *data;
  newNode->next = NULL;

  node *temp = behind;
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
