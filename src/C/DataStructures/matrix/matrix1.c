#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct{
  float *data;
  size_t rows;
  size_t cols;
  size_t length;
} mat;

// Inicia la matriz sin información
mat initMat(const size_t n, const size_t m){
  mat res;
  if (n == 0 || m == 0){
    fprintf(stderr, "La matriz debe ser mayor a 0\n");
    return res;
  }
  res.rows = n;
  res.cols = m;
  res.length = 0;
  res.data = malloc(n * m * sizeof(float));
  return res;
}

mat J(const size_t n, const size_t m){
  mat res;
  res.length = n * m;
  res.rows = n;
  res.cols = m;
  res.data = (float *)malloc(res.length * sizeof(float));
  for (size_t i = 0; i < res.length; i++)
    res.data[i] = 1.0f;
  return res;
}

void printM(mat *A){
  int n = A->rows;
  int m = A->cols;
  for (size_t i = 0; i < n; i++){
    for (size_t j = 0; j < m; j++){
      printf("%f ", A->data[i * m + j]); 
    }
    printf("\n");
  }
}
// Finaliza la matriz
void endMat(mat *matrix){
  if (!matrix) return;
  free(matrix->data);
  matrix->data = NULL; 
}

int main(){
  int n = 5;
  int m =  5;
  mat matrix = J(n,m);
  printM(&matrix);
  endMat(&matrix);
  printf("Esto es una prueba");
  return 0;
}
