/* maintains a parts database (array version) */

#include "readline.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;         // number of parts currently stored.
char f_name[FILENAME_MAX]; // stores file name provided by user, used to save to
                           // or load from the file.

int find_part(int number);
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
 *                       user enters the command 'q'. Prints an error message*
 *                       if the user enters an illegal code.                 *
 *****************************************************************************/
int main(void) {
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') // ski;s to the end of line
      ;
    switch (code) {
    case 'i':
      insert();
      break;
    case 'd':
      read_file_name("output");
      save(f_name);
      break;
    case 'r':
      read_file_name("input");
      restore(f_name);
      break;
    case 's':
      search();
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
 * find_part: Looks up a part number in the inventory array. Returns the     *
 *                       array index if the part number is found; otherwise, *
 *                       returns -1.                                         *
 *****************************************************************************/
int find_part(int number) {
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

/*****************************************************************************
 * insert: Prompts the user for information about a new part and then inserts*
 *                       the part into the database. Prints an error message *
 *                       and returns prematurely if the part already exists  *
 *                       or the database is full.                            *
 *****************************************************************************/
void insert(void) {
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

/*****************************************************************************
 * search: Prompts the user to enter a part number, then looks up the part in*
 *                       the database. If the part exists, prints the name   *
 *                       and quantity on hand; if not, prints an error       *
 *                       message.                                            *
 *****************************************************************************/
void search(void) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else
    printf("Part not found.\n");
}

/*****************************************************************************
 * update: Prompts the user to enter a part number. Prints an error message  *
 *                       if the part doesn't exist; otherwise, prompts the   *
 *                       user to enter change in quantity on hand and updates*
 *                       the database.                                       *
 *****************************************************************************/
void update(void) {
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

/*****************************************************************************
 * print: Prints a listing of all parts in the database, showing the part    *
 *                       number, number, part name and quantity on hand.     *
 *                       Parts are printed in the order in which they were   *
 *                       entered into the database.                          *
 *****************************************************************************/
void print(void) {
  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name,
           inventory[i].on_hand);
}

void save(char *str) {
  FILE *save_to;

  if ((save_to = fopen(str, "wb")) == NULL) {
    fprintf(stderr, "error: Can't open %s\n", str);
    return;
  }

  size_t written = fwrite(&inventory, sizeof(struct part), num_parts, save_to);

  if (written < (size_t)num_parts) {
    fprintf(stderr, "Error: at fwrite\n");
    fclose(save_to);
    exit(EXIT_FAILURE);
  }

  fclose(save_to);
}

void restore(char *str) {
  FILE *load_from;

  if ((load_from = fopen(str, "rb")) == NULL) {
    fprintf(stderr, "error: Can't open %s\n", str);
    return;
  }

  size_t read = fread(&inventory, sizeof(struct part), MAX_PARTS, load_from);

  if (ferror(load_from)) {
    fprintf(stderr, "Error: at fread\n");
    fclose(load_from);
    return;
  }

  num_parts = read;
  fclose(load_from);
}

char *read_file_name(const char *str) {
  printf("Enter name of %s file: ", str);
  scanf("%s", f_name);

  return f_name;
}
