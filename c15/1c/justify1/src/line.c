#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

 //now alternates between adding extra spaces at the end of the line then to the beginning of the line.
void write_line(void)
{
  int extra_spaces, base_spaces, leftovers, i, j;
  static int alternate = 0; // This variable persists across function calls to remember the last line's state. Used to track if the previous line was left biased (more spaces at the beginning of the line) or right biased (more spaces towards the end of the line).
  int current_gap = 0;
  int total_gaps = num_words - 1;

  if (num_words <= 1) {
    puts(line);
    return;
  }

  extra_spaces = MAX_LINE_LEN - line_len;
  base_spaces = extra_spaces / total_gaps; //the ammount of spaces each gap is supposed to get
  leftovers = extra_spaces % total_gaps; //the extra spaces left after allocating each gap an equal number of spaces.

  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ') {
      putchar(line[i]);
    } else {
      int spaces_to_print = base_spaces + 1; //when a space is encountered, the original space char and the baseline (spaces allocated evenly to each gap) are added.

      // Determine if this specific gap gets a leftover space based on the alternation state
      if (alternate == 0) {
        // Left-bias: Give leftovers to the first X gaps
        // since current_gap starts from 0, extra spaces are allocated to the first gaps
        if (current_gap < leftovers) {
          spaces_to_print++;
        }
      } else {
        // Right-bias: Give leftovers to the last X gaps
        // starts counting from the total number of gaps, moving backwards, ensuring the gaps towards the right (end) get the extra spaces
        if (current_gap >= (total_gaps - leftovers)) {
          spaces_to_print++;
        }
      }

      for (j = 0; j < spaces_to_print; j++) {
        putchar(' ');
      }

      current_gap++; // Move to the next gap index
    }
  }
  putchar('\n');

  // Flip the switch for the next line (0 becomes 1, 1 becomes 0) controls alteration between left bias and right bias
  alternate = !alternate;
}


void flush_line(void)
{
  if (line_len > 0)
    puts(line);
}
