#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

// Se define la estructura básica de una matriz 
typedef struct{
  float *data;
  size_t rows;
  size_t cols;
  size_t length;
} mat;

// Inicializa una matriz segura de valores 0
static inline mat matVacia(void){
  mat res = {0};
  return res;
}

// Inicia la matriz sin información
mat initMat(const size_t n, const size_t m){
  mat res = matVacia();
  if (n == 0 || m == 0){
    fprintf(stderr, "La matriz debe ser mayor a 0\n");
    res.cols = res.rows = res.length = 0;
    res.data = NULL;
    return res;
  }
  
  if (m != 0 && n > SIZE_MAX/m){
    fprintf(stderr, "Hay desbordamiento.\n");
    return matVacia();
  }

  res.rows = n;
  res.cols = m;
  res.length = n * m;
  res.data = (float *)malloc(n * m * sizeof(float));
  if (!res.data){
    fprintf(stderr,"Fallo al generar la memoria para el uso\n");
    return matVacia();
  }
  return res;
}

// Realiza la matriz de 1 estadística
mat J(const size_t n, const size_t m){
  mat res = initMat(n,m);
  if (!res.data) return res;
  for (size_t i = 0; i < res.length; i++)
    res.data[i] = 1.0f;
  return res;
}

// Realiza la matriz identidad
mat eyes(const size_t n){
  mat res = initMat(n,n);
  if (!res.data) return res;
  memset(res.data, 0, res.length * sizeof * res.data);
  for (size_t i = 0; i < n; i++){
    res.data[i * (n+1)] = 1.0f;
  } 
  return res;
}

void printM(mat *A){
  int n = A->rows, m = A->cols;
  for (size_t i = 0; i < n; i++){
    for (size_t j = 0; j < m; j++){
      printf("%f ", A->data[i * m + j]); 
    }
    printf("\n");
  }
}


// Finaliza la matriz
void endMat(mat *A){
  if (!A) return;
  free(A->data);
  A->data = NULL; 
  A->rows = A->cols = A->length = 0;
}

int main(){
  int n = 5;
  int m =  5;
  mat A = eyes(n); 
  printM(&A);
  endMat(&A);
  return 0;
}
