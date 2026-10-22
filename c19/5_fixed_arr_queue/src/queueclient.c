#include "queue.h"
#include <stdio.h>

int main(void) {
  Queue *s1, *s2;
  Item n;

  s1 = create_q();
  s2 = create_q();

  enqueue(s1, 1);

  enqueue(s1, 2);

  n = dequeue(s1);
  printf("dequeueped %d from s1\n", n);

  enqueue(s2, n);

  n = dequeue(s1);
  printf("dequeueped %d from s1\n", n);

  enqueue(s2, n);

  destroy_q(s1);

  while (!is_empty(s2)) {
    printf("dequeueped %d from s2\n", dequeue(s2));
  }

  enqueue(s2, 3);
  make_empty(s2);

  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy_q(s2);

  return 0;
}
