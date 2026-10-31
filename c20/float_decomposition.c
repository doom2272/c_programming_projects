#include <stdint.h>
#include <stdio.h>

union my_float {
  float my_float;
  struct {
    uint32_t fract_part : 23;
    uint32_t expon : 8;
    uint32_t sign_b : 1;
  };
};

int main(void) {
  union my_float ex;

  ex.sign_b = 1;
  ex.expon = 128;
  ex.fract_part = 0;

  printf("%f\n", ex.my_float);
}
