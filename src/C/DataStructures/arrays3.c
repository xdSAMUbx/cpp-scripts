#include <stdio.h>
#include <stdlib.h>

int main() {
  double x;
  int n;
  printf("Digite una cantida entera de números aleatoria: ");
  scanf("%d", &n);
  x = 0.0;
  // Así se declara un espacio en memoria
  double *arr = malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    arr[i] = x + 1.0 * (double)i;
    printf("%4.2f ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}
