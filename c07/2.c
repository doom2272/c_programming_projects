/* modify square.c so that it pauses after every 24 squares and displays the following:
"Press Enter to continue..."
*/
#include <stdio.h>

int main(void)
{
  int i, n;

  printf("This program prints a table of square.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n); // this scanf leaves a \n on the buffer, since it only store n and peeks but doesn't read the \n (enter) rom the user!!

  while (getchar() != '\n') //this while clears the buffer clears the \n from the buffer!
    ;

  for (i = 1; i <= n; i++){
    printf("%10d\t%10d\n", i, i * i);

    if (i % 24 == 0) {
       printf("Press Enter to continue...");

      while (getchar() != '\n')
        ;
    }
  }

  return 0;
}
