// swaps bytes in an unsigned short, which has 2 bytes.
// eg. 0x1234 becomes 0x3412

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define HEX 16

unsigned short swap_bytes(unsigned short i);

unsigned short hex_to_decimal(void);

int main(void) {

  unsigned short dec_value = hex_to_decimal();

  printf("Number with bytes swapped:  %#hx\n", swap_bytes(dec_value));

  return 0;
}

// single line body implementation of swap_bytes
unsigned short swap_bytes(unsigned short i) { return ((i >> 8) | (i << 8)); }

unsigned short hex_to_decimal(void) {
  char ch;
  unsigned short decimal = 0;
  int digit_count = 0;

  printf("Enter a hexadecimal number (up to four digits): ");
  while (digit_count < 4 && (ch = getchar()) != '\n' && ch != EOF) {

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
