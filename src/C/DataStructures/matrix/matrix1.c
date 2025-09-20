#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float *data;
  size_t rows;
  size_t cols;
  size_t length;
} mat;

// Inicia la matriz sin información
mat initMat(size_t n, const size_t m){
  mat res;
  res.rows = n;
  res.cols = m;
  res.length = 0;
  res.data = malloc(n * m * sizeof(float));
  return res;
}


// Finaliza la matriz
void endMat(mat *matrix){
  if (matrix && matrix->data){
    free(matrix->data);
    matrix->data = NULL;
    matrix->cols = 0;
    matrix->rows = 0;
  }
}

int main(){
  mat matrix = initMat(10,10);
  endMat(&matrix);
  return 0;
}
