//prompts user 2 dates then indicates which one comes earlier

#include <stdio.h>

int main(void)
{
  int m, m2, d, d2, y, y2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m, &d, &y);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m2, &d2, &y2);

  if (y < y2)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m, d, y, m2, d2, y2);
  else if (y == y2 && m < m2)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m, d, y, m2, d2, y2);
  else if (y == y2 && m == m2 && d < d2)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m, d, y, m2, d2, y2);
  else 
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m, d, y);

  return 0;
}
