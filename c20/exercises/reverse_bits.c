#include <stdio.h>

unsigned int reverse_bits(unsigned int n) {
  unsigned int new_bits = 0x0;

  for (int i = 0; i <= 31; i++) {
    new_bits <<= 1U;

    new_bits |= (n >> i) & 1;
  }

  return new_bits;
}

void print_binary(unsigned int num) {
  for (int i = 31; i >= 0; i--) {

    putchar((num & (1U << i)) ? '1' : '0');

    if (i % 4 == 0)
      putchar(' ');
  }
  putchar('\n');
}

int main(void) {
  unsigned int num, reversed_num;

  printf("Enter unsigned int: ");
  scanf("%u", &num);

  printf("Original binary:        ");
  print_binary(num);

  putchar('\n');

  reversed_num = reverse_bits(num);

  printf("Reversed unsigned int:  %u\n", reversed_num);
  printf("Reversed binary:        ");
  print_binary(reversed_num);
}
