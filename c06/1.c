#include <stdio.h>

int main(void)
{
  float input, max = 0.0f;

  printf("** program prints largest user input, to exit enter 0 **\n");
  
  while (input != 0) {
    if (input > max)
      max = input;
    printf("Enter a number: ");
    scanf("%f", &input);
  }
  printf("The largest number entered was %.2f\n", max);
}
