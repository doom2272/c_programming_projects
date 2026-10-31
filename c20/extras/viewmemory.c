#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned char BYTE;

int main(void) {
  uintptr_t addr; // uintptr_t is a fixed width type.
                  // to:
                  //    write data into in using scanf use - scanf("%" SCNxPTR,
                  //    &your_uintptr) to read from it using printf use   -
                  //    printf("%8" PRIXPTR " ", your_uintptr_variable)
  int i, n;
  BYTE *ptr;

  printf("Address of main function: %p\n", (void *)main);
  printf("Address of addr variable: %p\n", (void *)&addr);

  printf("\nEnter a (hex) address: ");
  scanf("%" SCNxPTR, &addr); // format token provided in <inttypes>, used to
                             // read a uintptr_t from scanf.
  printf("Enter number of bytes to view: ");
  scanf("%d", &n);

  printf("\n");
  printf(" Address                       Bytes                         "
         "Characters\n");
  printf(" -------  -------------------------------------------------  "
         "----------\n");

  ptr = (BYTE *)addr;

  // chunk size == 16
  for (; n > 0; n -= 16) {
    printf("%p  ", (void *)ptr); // Clean padding space

    // 1. Print the hexadecimal byte pairs
    for (i = 0; i < 16 && i < n; i++) {
      printf("%.2X ", *(ptr + i));
      if (i == 7)
        printf(" "); // Add an extra separating space right down the middle!
    }
    // Handle alignment padding for trailing incomplete lines
    for (; i < 16; i++) {
      printf("   ");
      if (i == 7)
        printf(" ");
    }

    printf("  "); // Spacer before the ASCII character text column

    // 2. Print printable characters or safe dots
    for (i = 0; i < 16 && i < n; i++) {
      BYTE ch = *(ptr + i);
      if (!isprint(ch))
        ch = '.';
      printf("%c", ch);
      if (i == 7)
        printf(" "); // Mirror the center line break in the character field too
    }
    printf("\n");
    ptr += 16;
  }

  return 0;
}
