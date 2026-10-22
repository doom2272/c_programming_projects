#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define PUBLIC
#define PRIVATE static

struct node {
  Item item;
  struct node *next;
};

struct Queue {
  struct node *first;
  struct node *last;
  int total;
};

PRIVATE void er(char *mess) {
  printf("%s\n", mess);
  exit(EXIT_FAILURE);
}

Queue *create_q(void) {
  Queue *q = malloc(sizeof(struct Queue));
  if (q == NULL)
    er("Error in create: queue could not be created ");

  q->first = NULL;
  q->last = NULL;
  q->total = 0;

  return q;
}

PUBLIC void destroy_q(Queue *q) {
  struct node *p = q->first;

  while (p != NULL) {
    q->first = q->first->next;

    free(p);
    p = q->first;
  }

  free(q);
}

PUBLIC void enqueue(Queue *q, Item i) {
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    er("Error in enqueue: new node could not be created ");

  new_node->item = i;
  new_node->next = NULL;

  if (q->first == NULL) {
    new_node->next = NULL;
    q->first = new_node;
    q->last = new_node;
  } else {
    q->last->next = new_node;

    q->last = new_node;
  }

  q->total++;
}

PUBLIC Item dequeue(Queue *q) {
  Item i = 0;

  if (is_empty(q))
    er("Error in dequeue: queue is empty.");

  if (q->total == 1) {
    i = q->last->item;

    struct node *temp = q->last;
    q->last = NULL;
    q->first = NULL;

    free(temp);
    q->total--;

    return i;
  }

  i = q->first->item;

  struct node *temp = q->first;

  q->first = q->first->next;
  free(temp);

  q->total--;
  return i;
}

PUBLIC Item peek_front(const Queue *q) {
  if (is_empty(q))
    er("Error at peek front: Queue is empty");

  return q->first->item;
}

PUBLIC Item peek_rear(const Queue *q) {
  if (is_empty(q))
    er("Error at peek front: Queue is empty");

  return q->last->item;
}

bool is_empty(const Queue *q) { return q->total == 0; }

PUBLIC void make_empty(Queue *q) {
  while (!is_empty(q))
    dequeue(q);
}
