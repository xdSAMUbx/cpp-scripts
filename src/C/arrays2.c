#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 5;

  int *arr = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i] = i;
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}
