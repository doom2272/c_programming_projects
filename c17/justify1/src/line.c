#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
  char *word;
  struct node *next;
};

struct node *line = NULL;  //head pointer

struct node **tracker = &line; //pointer to the slot where the next node goes

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  struct node *cur = line;
  while (cur != NULL) {
    line = line->next;
    free(cur->word);
    free(cur);
    cur = line;
  }

  tracker = &line;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{

  struct node *new_node = malloc(sizeof(struct node));

  new_node->word = malloc(strlen(word) + 1);
  strcpy(new_node->word, word);
  new_node->next = NULL;

  *tracker = new_node;

  tracker = &(new_node->next);

  
  line_len += strlen(new_node->word);

  if (num_words > 0)
   line_len++;

  num_words++;
}


int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}


void write_line(void)
{
  int extra_spaces, spaces_to_insert, temp_num_words = num_words;
  extra_spaces = MAX_LINE_LEN - line_len;

  struct node *cur = line;

  while (cur != NULL) {

    printf("%s", cur->word);

    if (cur->next != NULL) {

      spaces_to_insert = extra_spaces / (temp_num_words - 1);
      
      for (int j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');

      extra_spaces -= spaces_to_insert;
      temp_num_words--;
    }

    cur = cur->next;
  }

  putchar('\n');
}


void flush_line(void)
{
  struct node *cur = line;

  while (cur != NULL) {
    if (cur->next != line->next)
      putchar(' ');
    printf("%s", cur->word);

    cur = cur->next;
  }

  putchar('\n');
}
