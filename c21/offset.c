#include <stddef.h>
#include <stdio.h>

struct s {
  char a;
  int b[2];
  float c;
};

int main(void) {

  struct s tes;

  printf("Size of member a: %zu \n", sizeof(tes.a));
  printf("Offset of member a: %zu \n", offsetof(struct s, a));
  putchar('\n');
  printf("Size of member b: %zu \n", sizeof(tes.b));
  printf("Offset of member b: %zu \n", offsetof(struct s, b));
  putchar('\n');
  printf("Size of member c: %zu \n", sizeof(tes.c));
  printf("Offset of member c: %zu \n", offsetof(struct s, c));
  putchar('\n');
  printf("Size of struct s: %zu \n", sizeof(tes));

  return 0;
}
