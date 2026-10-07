#ifndef READLINE_H
#define READLINE_H


/*****************************************************************************
 * read_line: Reads a line of input until a '\n'. Stores upto to n characters*
 *                       in the str array and appends a '\0' at the end to   *
 *                       create a valid string. Characters beyond the limit n*
 *                       are discarded. Returns the length of the sting      *
 *                       stored in str.                                      *
 *****************************************************************************/
int read_line(char str[], int n);

#endif
