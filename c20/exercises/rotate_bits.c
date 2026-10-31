#include <ctype.h>
#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int hex_to_decimal(void);
unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);
void print_binary(unsigned int num);

int main(void) {

  char direction;

  unsigned int hex = hex_to_decimal();

  int clear_ch;

  while ((clear_ch = getchar()) != '\n' && clear_ch != EOF)
    ;

  printf("Do you want to rotate bits to the left or right? (l or r): ");
  while (scanf(" %c", &direction) == 1) {
    if (direction == 'l' || direction == 'r') {
      int shift_ammount = 0;

      printf("You want to shift the '%c' by how many places? ", direction);
      if (scanf("%d", &shift_ammount) == 1) {
        unsigned int rotated_hex = 0;

        direction == 'l' ? (rotated_hex = rotate_left(hex, shift_ammount))
                         : (rotated_hex = rotate_right(hex, shift_ammount));

        printf("Your original hex value: %#x\n", hex);
        printf("Original binary:         ");
        print_binary(hex);
        printf("\nShifted hex: %#x\n", rotated_hex);
        printf("Shifted binary:          ");
        print_binary(rotated_hex);
        return 0;
      } else {
        printf("Incorrect shift ammount. Enter a valid number.");
        return 1;
      }
    } else {
      printf("Invalid character: Pick either 'l' or 'r'  ");
    }
  }
  printf("Direction should be a valid character. 'l' or 'r' \n");

  return 1;
}

unsigned int rotate_left(unsigned int i, int n) {

  n = n % 32;

  if (n < 0)
    n += 32;

  if (n == 0)
    return i;

  return (i << n) | (i >> (32 - n));
}
unsigned int rotate_right(unsigned int i, int n) {

  n = n % 32;

  if (n < 0)
    n += 32; // if a user wants to shift by a negative to the right, e.g by -1,
             // this is the same as shifting to the left by 1 (you are walking
             // backwards essentially)

  if (n == 0)
    return i;
  return (i >> n) | (i << (32 - n));
}

unsigned int hex_to_decimal(void) {
  char ch;
  unsigned int decimal = 0;
  int digit_count = 0;

  printf("Enter a hexadecimal number (up to eight digits): ");
  while (digit_count < 8 && (ch = getchar()) != '\n' && ch != EOF) {

    int current_num = 0;

    if (isdigit(ch))
      current_num = ch - '0';
    else {
      ch = tolower(ch);

      if (ch >= 'a' && ch <= 'f') {
        current_num = ch - 'a' + 10;
      } else {
        printf("Invalid hexadecimal character: use (0-9) or (a-f)\n");
        exit(EXIT_FAILURE);
      }
    }

    decimal = (decimal << 4) | current_num;
    digit_count++;
  }

  return decimal;
}

void print_binary(unsigned int num) {
  for (int i = 31; i >= 0; i--) {

    putchar((num & (1U << i)) ? '1' : '0');

    if (i % 4 == 0)
      putchar(' ');
  }
  putchar('\n');
}
