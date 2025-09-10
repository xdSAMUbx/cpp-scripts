#include <stdio.h>

int main() {
  int arr[5];
  for (int i = 0; i < 5; i++) {
    arr[i] = i;
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
