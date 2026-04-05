// modify project 11 so that terms are continuosly added until the current term becomes less than epsilon (which is a small float point number entered by the user). project12 tells comp to stop at certain accuracy, i.e , when e is less than epsilon

#include <stdio.h>
int main(void)
{
  int i = 1;
  float epsilon;
  float e = 1.0f, factorial = 1.0f;
  float term = 1.0f / factorial;

  printf("** program uses accuracy entered by user to stop calculating e **\n");

  printf("\n Enter epsilon (eg 0.000001): ");
  scanf("%f", &epsilon);

  while (term >= epsilon) {
    e += term;

    i++;
    factorial *= i;
    term = 1.0f / factorial;
  }

  printf("Approximation of e: %f\n", e);

}
