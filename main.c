#include "aliases.h"
#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

i32 main(i32 argc, char *argv[]) {
  VEC(int, 3) vec1 = {4, 10, 8};
  PRINT_VEC(int, 3)(&vec1);
  printf("\n");

  VEC(float, 2) vec2 = {1.4f, 2.0f};
  PRINT_VEC(float, 2)(&vec2);
  printf("\n");

  VEC(double, 4) vec3 = {2.3, 8.5, 9.2, 1.0};
  PRINT_VEC(double, 4)(&vec3);
  printf("\n");

  return EXIT_SUCCESS;
}
