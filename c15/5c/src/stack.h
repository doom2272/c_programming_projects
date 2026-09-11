#ifndef STACK_H
#define STACK_H

/*****************************************************************************
 * make_empty: resets the stack array, by making the top variable index 0.   *
 *****************************************************************************/
void make_empty(void);


/*****************************************************************************
 * stack_underflow: Prints error message when you try to go below/before     *
 *                       element 0 in stack array. Also causes the program to*
 *                       exit immediately.                                   *
 *****************************************************************************/
void stack_underflow(void);


/*****************************************************************************
 * stack_overflow: Prints error message when you try to go above/after       *
 *                       element 100 in stack array. Also causes the program *
 *                       to exit immediately.                                *
 *****************************************************************************/
void stack_overflow(void);


/*****************************************************************************
 * is_empty: checks if the stack array is empty, where top is equal to 0.    *
 *****************************************************************************/
bool is_empty(void);


/*****************************************************************************
 * is_full: Checks if stack array is full, i.e, top is 100.                  *
 *****************************************************************************/
bool is_full(void);


/*****************************************************************************
 * push: Adds i to the stack array.                                          *
 *****************************************************************************/
void push(int i);


/*****************************************************************************
 * pop: Returns integer at the 'top of the stack'.                           *
 *****************************************************************************/
int pop(void);

#endif
