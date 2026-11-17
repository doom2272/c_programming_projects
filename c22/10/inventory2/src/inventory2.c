// maintains a parts database (linked list version)
// adds the d (dump parts to file)and r (load parts from a file) operations

#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL; // points to first part
char f_name[FILENAME_MAX]; // stores file name provided by user, used to save to
                           // or load from the file.
struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void save(char *str);
void restore(char *str);
char *read_file_name(const char *str);

/*****************************************************************************
 * main: Prompts the user to enter an operation code, then calls a function  *
 *                       to perform the requested action. Repeats until the  *
 *                       user enter the command 'q'. Prints an error message *
 *                       if the user enters an illegal code.                 *
 *****************************************************************************/
int main(void) {
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
      ;
    switch (code) {
    case 'i':
      insert();
      break;
    case 's':
      search();
      break;
    case 'd':
      read_file_name("output");
      save(f_name);
      break;
    case 'r':
      read_file_name("input");
      restore(f_name);
      break;
    case 'u':
      update();
      break;
    case 'p':
      print();
      break;
    case 'q':
      return 0;
    default:
      printf("Illegal code\n");
    }
    printf("\n");
  }
}

/*****************************************************************************
 * find_part: Looks up a part number in the inventory list. Returns a pointer*
 *                       to the node containing the part number. If part     *
 *                       number is not found, returns NULL.                  *
 *****************************************************************************/
struct part *find_part(int number) {
  struct part *p;

  for (p = inventory; p != NULL && number > p->number; p = p->next)
    ;

  if (p != NULL && number == p->number)
    return p;
  return NULL;
}

/*****************************************************************************
 * insert: Prompts user for the information about a new part and then inserts*
 *                       the part into the inventory list; the list remains  *
 *                       sorted by part number. Prints an error message and  *
 *                       returns prematurely if the part already exists or   *
 *                       space could not be allocated for the part.          *
 *****************************************************************************/
void insert(void) {
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

/*****************************************************************************
 * search: Prompts the user to enter a part number, then looks up the part in*
 *                       the database. If the part exists, prints the name   *
 *                       and quantity on hand. If not, prints an error       *
 *                       message.                                            *
 *****************************************************************************/
void search(void) {
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else
    printf("Part not found.\n");
}

/*****************************************************************************
 * update: Prompts the user to enter a part number. Prints an error message  *
 *                       if the part doesn't exist. Otherwise, prompts the   *
 *                       user to enter change in quantity on hand and update *
 *                       the database.                                       *
 *****************************************************************************/
void update(void) {
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else
    printf("Part not found.\n");
}

/*****************************************************************************
 * print: Prints a listing of all parts in the database, showing the part    *
 *                       number, part name and quantity on hand. Part numbers*
 *                       will appear in ascending order.                     *
 *****************************************************************************/
void print(void) {
  struct part *p;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
}

void save(char *str) {
  FILE *save_to;

  if ((save_to = fopen(str, "wb")) == NULL) {
    fprintf(stderr, "error: Can't open %s\n", str);
    return;
  }

  struct part *p = inventory;

  for (p = inventory; p != NULL; p = p->next) {
    fwrite(&p->number, sizeof(p->number), 1, save_to);
    fwrite(p->name, sizeof(p->name), 1, save_to);
    fwrite(&p->on_hand, sizeof(p->on_hand), 1, save_to);
  }

  fclose(save_to);
}

void restore(char *str) {
  FILE *load_from;

  if ((load_from = fopen(str, "rb")) == NULL) {
    fprintf(stderr, "error: Can't open %s\n", str);
    return;
  }

  while (inventory != NULL) {
    struct part *temp = inventory;
    inventory = inventory->next;
    free(temp);
  }

  struct part *tail = NULL, *new_node;
  int number;

  while ((fread(&number, sizeof(int), 1, load_from)) == 1) {

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
      printf("Database is full!! Can't add more parts.\n");
      fclose(load_from);
      return;
    }

    new_node->number = number;

    if (tail != NULL && new_node->number <= tail->number) {
      fprintf(stderr, "Error: part not in order\n");
      free(new_node);
      fclose(load_from);
      return;
    }

    if ((fread(new_node->name, sizeof(new_node->name), 1, load_from)) != 1) {
      perror("fread");
      free(new_node);
      fclose(load_from);
      return;
    }

    if ((fread(&new_node->on_hand, sizeof(int), 1, load_from)) != 1) {
      perror("fread");
      free(new_node);
      fclose(load_from);
      return;
    }

    new_node->next = NULL;
    if (tail == NULL) {
      inventory = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  fclose(load_from);
}

char *read_file_name(const char *str) {
  printf("Enter name of %s file: ", str);
  scanf("%s", f_name);

  return f_name;
}
