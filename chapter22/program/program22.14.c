#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main(void) {
  FILE *fp_src, *fp_des;
  char c, filename[MAX_LEN], *outfile;
  int key;

  printf("Enter name of file to be encrypted: ");
  scanf("%s", filename);

  if ((fp_src = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error: file %s cannot be opened\n", filename);
    exit(EXIT_FAILURE);
  }

  outfile = malloc(strlen(filename) + 5);
  strcpy(outfile, filename);
  strcat(outfile, ".enc");

  if ((fp_des = fopen(outfile, "w")) == NULL) {
    fprintf(stderr, "Error: file %s cannot be written\n", outfile);
    exit(EXIT_FAILURE);
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &key);

  while ((c = getc(fp_src)) != EOF) {
    if (c >= 'A' && c <= 'Z')
      putc(((c - 'A') + key) % 26 + 'A', fp_des);
    else if (c >= 'a' && c <= 'z')
      putc(((c - 'a') + key) % 26 + 'a', fp_des);
    else
      putc(c, fp_des);
  }
  fclose(fp_src);
  fclose(fp_des);

  exit(EXIT_SUCCESS);
}