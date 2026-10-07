/*
displays user input,16 digits, then displays it in 4*4 square.
it hten adds all the rows, columns and diagonal sums and displays it.
*/

#include <stdio.h>

int main(void)
{
  int A, B, C, D, E, F, G, H, a, b, c, d, e, f, g, h, r1, r2, r3, r4, c1, c2, c3, c4, d1, d2;

  printf("Enter the numbers from 1 to 16 in any order:\n");
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &A, &B, &C, &D, &a, &b, &c, &d, &E, &F, &G, &H, &e, &f, &g, &h);

  printf("\n");

  r1 = A + B + C + D;
  r2 = a + b + c + d;
  r3 = E + F + G + H;
  r4 = e + f + g + h;

  c1 = A + a + E + e;
  c2 = B + b + F + f;
  c3 = C + c + G + g;
  c4 = D + d + H + h;

  d1 = A + b + G + h;
  d2 = D + c + F + e;

  printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n\nRow sums: %d %d %d %d\nColumn sums: %d %d %d %d\nDiagonal sums: %d %d\n", A, B, C, D, a, b, c, d, E, F, G, H, e, f, g, h, r1, r2, r3, r4, c1, c2, c3, c4, d1, d2);

  return 0;
}
