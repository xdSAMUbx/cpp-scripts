#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int *data; // Permite generar la memoria dinámica 
  size_t size; // Permite conocer la capacidad máx
  size_t length; // Permite saber cuantos estan usados
} vector;

vector initVec(size_t n){
  vector res;
  res.data = malloc(n * sizeof(int));
  res.size = n;
  return res;
}

void insert(vector *arr, int val){
  if(arr->length == arr->size){
    size_t newSize = (arr->size == 0) ? 1 : arr->size * 2;
    int *tmp = realloc(arr->data, newSize * sizeof(int));
    if (!tmp){
      perror("Ya no hay más espacio");
      exit(1);
    }
    arr->data = tmp;
    arr->size = newSize;
  }
  arr->data[arr->length] = val;
  arr->length++;
}

int len(vector *arr){
  return (int) arr->size;
}

void printVec(vector *arr){
  printf("[ ");
  for (int i = 0; i < arr->size; i++){
    printf("%d ", arr->data[i]);
  }
  printf("]\n");
}

void endVec(vector *arr){
  if (arr && arr->data){
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
  }
}

int main(){
  int n = 5;
  vector arr = initVec(n);
  printVec(&arr);
  printf("La cantidad de elementos es: %d\n", len(&arr));
  endVec(&arr);
  return 0;
}
