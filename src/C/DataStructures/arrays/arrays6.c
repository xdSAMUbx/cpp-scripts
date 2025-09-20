#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Con esta función se pueden hacer los vectores aleatorios

typedef struct{
  float *data; // Permite generar la memoria dinámica 
  size_t size; // Permite conocer la capacidad máx
  size_t length; // Permite saber cuantos estan usados
} vector;

// Esta función permite crear un vector y tenerlo en memoria
vector initVec(size_t n){
  vector res;
  res.data = malloc(n * sizeof(float));
  res.size = n;
  res.length = 0;
  return res;
}

// Esta función permite contar cuantos valores hay dentro del vector
int len(vector *arr){
  return (int) arr->size;
}

// Esta función permite imprimir el vector al estilo python
void printVec(vector *arr){
  printf("[ ");
  for (size_t i = 0; i < arr->size; i++){
    printf("%.2f ", arr->data[i]);
  }
  printf("]\n");
}

// Esta función genera un vector de unos
vector ones(size_t n){
  vector res;
  res.data = malloc(n * sizeof(float));
  res.size = n;  
  for (size_t i = 0; i < res.size; i++)
    res.data[i] = 1.0;
  res.length = n;
  return res;
}

// Esta función genera un vector de ceros
vector zeros(size_t n){
  vector res;
  res.data = malloc(n * sizeof(float));
  res.size = n;
  for (size_t i = 0; i < res.size; i++)
    res.data[i] = 0.0;
  res.length = n;
  return res;
}

// Esta función permite generar un vector aleatorio
vector randVec(size_t n, float min, float max){
  static int seed = 0;
  if(!seed){
    srand((unsigned) time(NULL));
    seed = 1;
  }
  vector res;
  res.data = malloc(n * sizeof(float));
  res.size = n;
  for (size_t i = 0; i < res.size; i++)
    res.data[i] = min + ((float)rand() / RAND_MAX) * (max-min);
  res.length = n;
  return res;
}

// Esta función permite eliminar el vector correspondiente
void endVec(vector *arr){
  if (arr && arr->data){
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
  }
}

int main(){
  int n = 5;
  vector arr = randVec(n,1.0,10.0);
  printVec(&arr);
  printf("La cantidad de elementos es: %d\n", len(&arr));
  endVec(&arr);
  return 0;
}
