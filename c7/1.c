// modify square.c which originally declared i and n as int. I also declared i and n as short and long type. the different results are below.
/*
short -> when n was 181 and square was 32,761, this was the last correct value all the rest were incorrect (eg had negative numbers).
int -> n was 46,340, square was 2.1billion, this was the right last answer.
long -> the runtime was too long i had to quit but its safe to say if n was 1 billion, we still might have a right answer!!

from the details above my machine is likely a 64 bit machine because of the max and min values of signed intergers it can handle.
*/

#include <stdio.h>

int main(void)
{
  long i, n;  //changed from int, to short and finally to long

  printf("This program prints a table of square.\n");
  printf("Enter number of entries in table: ");
  scanf("%ld", &n);//the conversion specifications of int is %d, short is %hd, long is %ld

  for (i = 1; i <= n; i++)
    printf("%10ld\t%10ld\n", i, i * i);

  return 0;
}
