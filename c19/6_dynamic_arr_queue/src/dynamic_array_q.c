#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define PUBLIC
#define PRIVATE static

struct Queue {
  Item *contents;
  Item top;
  Item first;
  Item total;
  int size;
};

PRIVATE void er(char *mess) {
  printf("%s\n", mess);
  exit(EXIT_FAILURE);
}

Queue *create_q(int size) {
  Queue *q = malloc(sizeof(struct Queue));
  if (q == NULL)
    er("Error in create: queue could not be created ");

  q->size = size;

  Item *temp = malloc(q->size * sizeof(Item));
  if (temp == NULL)
    er("Err: failure at creating queue. Not enough space!");

  q->contents = temp;

  q->top = 0;
  q->first = 0;
  q->total = 0;

  return q;
}

PUBLIC void destroy_q(Queue *q) {

  free(q->contents);
  free(q);
}

PUBLIC void enqueue(Queue *q, Item i) {
  if (is_full(q))
    er("Error in enqueue: queue is full");

  q->contents[q->top] = i;

  q->top = (q->top + 1) % q->size;
  q->total++;
}

PUBLIC Item dequeue(Queue *q) {
  if (is_empty(q)) {
    er("Error in dequeue: queue is empty");
  }

  Item removed_item = q->contents[q->first];

  q->first = (q->first + 1) % q->size;
  q->total--;

  return removed_item;
}

PUBLIC Item peek_front(const Queue *q) {
  if (is_empty(q))
    er("Error at peek front: Queue is empty");

  return q->contents[q->first];
}

PUBLIC Item peek_rear(const Queue *q) {
  if (is_empty(q))
    er("Error at peek front: Queue is empty");

  Item rear_ind = (q->top - 1 + q->size) % q->size;
  return q->contents[rear_ind];
}

bool is_empty(const Queue *q) { return q->total == 0; }

bool is_full(const Queue *q) { return q->total == q->size; }

PUBLIC void make_empty(Queue *q) {
  while (!is_empty(q))
    dequeue(q);
}
