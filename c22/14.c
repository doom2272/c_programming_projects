/*
 * uses Ceasar cipher to encrypt message. shifts letters according to user
 * specification.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int main(void) {
  int shift, c;
  char fname[N];

  printf("Enter name of file to be encrypted: ");
  fgets(fname, sizeof(fname), stdin);
  fname[strcspn(fname, "\n")] = '\0';

  FILE *in;
  if ((in = fopen(fname, "r")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", fname);
    exit(EXIT_FAILURE);
  }

  char enc_fname[strlen(fname) + 5];
  snprintf(enc_fname, sizeof(enc_fname), "%s.enc", fname);

  FILE *enc_fp;
  if ((enc_fp = fopen(enc_fname, "w")) == NULL) {
    fprintf(stderr, "Cannot write to %s\n", enc_fname);
    fclose(in);
    exit(EXIT_FAILURE);
  }

  printf("Enter shift ammount (1 - 25): ");
  scanf("%d", &shift); // ask for shift

  if (shift < 1 || shift > 25) {
    printf("%d is out of bounds. Pick number between 1 - 25\n",
           shift); // make sure shift is in the boundary
    fclose(in);
    fclose(enc_fp);
    return 1;
  }

  while ((c = getc(in)) != EOF) {
    if (isupper(c))
      putc(((c - 'A') + shift) % 26 + 'A', enc_fp);
    else if (islower(c))
      putc(((c - 'a') + shift) % 26 + 'a', enc_fp);
    else
      putc(c, enc_fp);
  }

  if (ferror(in)) {
    fprintf(stderr, "Read error occured\n");
    fclose(in);
    fclose(enc_fp);
    exit(EXIT_FAILURE);
  }

  fclose(in);
  fclose(enc_fp);

  return 0;
}
