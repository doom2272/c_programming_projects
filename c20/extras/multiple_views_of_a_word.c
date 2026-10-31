#include <stdio.h>

int main(void) {
  union {
    struct {
      unsigned short ax, bx;
    } word;
    struct {
      unsigned char al, ah, bl, bh;
    } byte;
  } regs;

  regs.byte.ah = 0x12;
  regs.byte.al = 0x34;

  printf("AX: %#hx\n", regs.word.ax);

  putchar('\n');

  unsigned char *ptr = (unsigned char *)&regs;

  printf("In mem, the register is stored as %#hX (lsbyte) then %#hX (msbyte)\n",
         *ptr, *(ptr + 1));

  return 0;
}
