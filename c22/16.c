// copies a file in blocks of 512 bytes

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char **argv) {
  int status = EXIT_FAILURE;
  FILE *source_fp = NULL, *dest_fp = NULL;
  char buff[BLOCK];

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if ((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Could not open %s\n", argv[1]);
    goto cleanup;
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Could not open %s\n", argv[2]);
    goto cleanup;
  }

  size_t read;
  while ((read = fread(buff, sizeof(buff[0]), BLOCK, source_fp)) != 0) {
    size_t written = fwrite(buff, read, 1, dest_fp);

    if (written < 1) {
      fprintf(stderr, "error: Write error occured!!\n");
      goto cleanup;
    }
  }

  if (ferror(source_fp)) {
    fprintf(stderr, "Error: Read error occured!!\n");
    goto cleanup;
  }

  status = EXIT_SUCCESS;

cleanup:
  if (source_fp != NULL)
    fclose(source_fp);
  if (dest_fp != NULL)
    fclose(dest_fp);
  return status;
}
