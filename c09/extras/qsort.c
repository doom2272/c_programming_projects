/*
 * sorts a 1D array.
 */

#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high); //declares function
int split(int a[], int low, int high); //declares functions. both this function declarations give the compiler a hint that there is a full defination somewhere

int main(void)
{
  int a[N], i = 0, ch;


  printf("Enter upto %d numbers to be sorted: ", N);
  do {

    if (scanf("%d", &a[i]) == 1) { // populates user input into a[]
      i++;
    }

    while ((ch = getchar()) == ' '); // skips any trailing spaces (if there are any) after user input

  }while (ch != '\n' && i < N); // exit reading loop if numbers exceed N or if input is ENTER, which shows user's input is done

  quicksort(a, 0, i - 1); // calls quicksort, first argument is array a, sencond is first element, third is last element in a[]

  printf("In sorted order: ");
  for (int j = 0; j < i; j++)
    printf("%d ", a[j]); // prints sorted array after quicksort is called

  printf("\n");

  return 0;
}

void quicksort(int a[], int low, int high) // return type is void, expects array and the first and last element. this function splits a into sub arrays and tries to sort them.
{
  int middle;

  if (low >= high) return; // it can mean 2 things; if low == high, that means our sub array is a single digit, that makes it already sorted.
                           // if low > high, that means the sub array is empty.
  middle = split(a, low, high); // calls split to divided and conqure the array
  quicksort(a, low, middle - 1); // quicksort calls its self to sort the elements on the left (smaller values). calls split with a new last element
  quicksort(a, middle + 1, high);//calls itself again to sort the elements on the right(larger values). calls split with a new first element
}

int split(int a[], int low, int high) // returns an int value, expects an array, first and last element
{
  int part_element = a[low]; // takes the first element as the testing number, any number less than it gets moved to the left side, and vice versa

  for (;;) {
    while (low < high && part_element <= a[high]) //starts reading the number from the right side, if a number is larger than our test number move to the next number on the left
      high--;
    if (low >= high) break; //if at any point the first array index == the last array index , this is the correct position for our test number.
    a[low++] = a[high]; //if a number is less than our test number and its on the right side, it copied to the left side, and our first number is incremented, so we ingnore that value in that index since we just moved it to the correct side.

    while (low < high && a[low] <= part_element) // this loop does the exact opposite of the first one, reads our array from the left to right and copies any number larger than our test number to the right.
      low++;
    if (low >= high) break;
    a[high--] = a[low];
  }

  a[high] = part_element; //remember where our first and last indices meet, that is the only valid position for our test number. we copy it there. now all the number less than it are on the left side, those greater than it are on the right side.

  return high;
}
