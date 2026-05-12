//add a loop to broker.c so user can enter more than one trade and get the commiossion, the program should terminate when user inputs 0.

#include <stdio.h>

int main(void)
{
  
  float commission, value;

  printf("Enter value of trade: "); // the first printf and scanf(outside the loop) ensure the program terminates when user enter 0 as input.
  scanf("%f", &value);
  
  while (value != 0) {

    if (value < 2500.00f)
    commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
      commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
      commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
      commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
      commission = 155.00f + .0011f * value;
    else 
      commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
      commission = 39.00f;

    printf("Commission: $%.2f\n", commission);

    printf("Enter value of trade (0 to quit): "); //user friendly lets user understand the program.
    scanf("%f", &value);
    
  }


 // printf("Commission: $%.2f\n", commission);
}
