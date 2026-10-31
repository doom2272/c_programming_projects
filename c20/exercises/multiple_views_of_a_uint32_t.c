#include <stdint.h>
#include <stdio.h>

typedef unsigned long DWORD;

int main(void) {
  union {
    struct {
      DWORD eax, ebx, ecx, edx;
    } dword;
    struct { // all unnamed members are dummy dummy bytes.
      uint16_t ax : 16;
      uint16_t : 16;
      uint16_t bx : 16;
      uint16_t : 16;
      uint16_t cx : 16;
      uint16_t : 16;
      uint16_t dx : 16;
      uint16_t : 16;
    } word;
    struct {
      uint8_t al : 8;
      uint8_t ah : 8;
      uint8_t : 8;
      uint8_t : 8;
      uint8_t bl : 8;
      uint8_t bh : 8;
      uint8_t : 8;
      uint8_t : 8;
      uint8_t cl : 8;
      uint8_t ch : 8;
      uint8_t : 8;
      uint8_t : 8;
      uint8_t dl : 8;
      uint8_t dh : 8;
      uint8_t : 8;
      uint8_t : 8;
    } byte;
  } regs;

  // Assign a test pattern to the full 32-bit register
  regs.dword.eax = 0x12345678;

  printf("EAX: 0x%08lX\n", regs.dword.eax); // 0x12345678
  printf("AX:  0x%04X\n", regs.word.ax);    // 0x5678 (The lower half)
  printf("AH:  0x%02X\n", regs.byte.ah);    // 0x56   (High byte of AX)
  printf("AL:  0x%02X\n", regs.byte.al);    // 0x78   (Low byte of AX)

  return 0;
}
