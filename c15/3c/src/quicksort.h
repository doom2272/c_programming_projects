#ifndef QUICKSORT_H
#define QUICKSORT_H


/*****************************************************************************
 * quicksort: Uses value from split as a middle/pivot. split returns the     *
 *                       index of one element that is correctly placed in the*
 *                       array. quicksort uses this element as a middle point*
 *                       to dissect the array into subarrays. the function   *
 *                       then calls itself recursively to sort the subarrays *
 *                       to the left and right of the middle.                *
 *****************************************************************************/
void quicksort(int a[], int low, int high); 


/*****************************************************************************
 * split: places the first element in its correct position in the array. Such*
 *                       that every number to the left of it is less than it *
 *                       and every number to the right is greater than it.   *
 *****************************************************************************/
int split(int a[], int low, int high);

#endif
