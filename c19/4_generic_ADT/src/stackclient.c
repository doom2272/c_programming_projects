#include "stackADT.h"
#include <stdio.h>

int main(void) {
  Stack *s1, *s2;
  char *n;

  s1 = create();
  s2 = create();

  push(s1, "Hello");
  push(s1, "World!");

  n = pop(s1);
  printf("Popped %s from s1\n", n);

  push(s2, n);

  n = pop(s1);
  printf("Popped %s from s1\n", n);

  push(s2, n);

  destroy(s1);

  while (!is_empty(s2)) {
    printf("Popped %s from s2\n", (char *)pop(s2));
  }

  push(s2, "To c, or not to c: that is the question");
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}
