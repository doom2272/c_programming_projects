#pragma once

#include <stdbool.h>

typedef struct Queue Queue;

typedef int Item;

Queue *create_q(int size);
void destroy_q(Queue *q);

void enqueue(Queue *q, Item i);
bool is_full(const Queue *q);
bool is_empty(const Queue *q);
Item peek_front(const Queue *q);
Item peek_rear(const Queue *q);
Item dequeue(Queue *q);
void make_empty(Queue *q);
