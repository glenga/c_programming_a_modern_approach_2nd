#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int array[MAX_SIZE];

int compare(const void *a, const void *b);

int main(int argc, char *argv[]) {
  if (2 != argc) {
    fprintf(stderr, "Error: missing file name.\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;

  if (NULL == (fp = fopen(argv[1], "r"))) {
    fprintf(stderr, "error open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int i = 0;

  while (!feof(fp) && i < MAX_SIZE) {
    fscanf(fp, "%d", &array[i]);
    i++;
  }

  qsort(array, i, sizeof(int), compare);

  if (i % 2 == 0)
    printf("min: %d, mid: %d, max: %d\n", array[0], array[i / 2], array[i - 1]);
  else
    printf("min: %d, mid: %d, max: %d\n", array[0],
           (array[i / 2] + array[(i - 1) / 2]) / 2, array[i - 1]);

  fclose(fp);
  return 0;
}

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }