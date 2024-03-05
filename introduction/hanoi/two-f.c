#include <stdio.h>
#include <stdlib.h>
int f(int n) {
  if (n <= 1) return 1;
  return f(n - 1) + g(n - 2);
}

int g(int n) {
  if (n <= 1) return 1;
  return f(n + 1) + g(n - 1);
}

int main(int argc, char *argv[]) {
  int result_f = f(3);
  int result_g = g(3);

  printf("Result of f: %d\n", result_f);
  printf("Result of g: %d\n", result_g);

  return EXIT_SUCCESS;
}
