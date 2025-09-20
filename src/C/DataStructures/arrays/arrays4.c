#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double *val;
  size_t tamaño;
} vector;

vector makeVec(size_t n) {
  vector res;
  res.val = malloc(n * sizeof(double));
  res.tamaño = n;
  for (size_t i = 0; i < n; i++)
    res.val[i] = (double)i + 1.0;
  return res;
}

int main() {
  vector vec;
  vec = makeVec(5);
  for (int i = 0; i < vec.tamaño; i++)
    printf("%4.2f ", vec.val[i]);
  printf("\n");
  free(vec.val);
  return 0;
}
