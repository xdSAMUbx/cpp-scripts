#include <stdio.h>

#define LOWER 0 // Esta es la forma de definir constantes
#define UPPER 200
#define STEP 20

int main() {
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
