#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * ans = malloc(sizeof(*ans));
  ans -> cntArr = NULL;
  ans -> cntSize = 0;
  ans -> unknown = 0;
  return ans;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL) c -> unknown ++;
  else {
    one_count_t * x = NULL;
    int h = 0;
    for (size_t i = 0; i < c -> cntSize; i++){
      x = c -> cntArr[i];
      if (! strcmp(x -> str, name)){
	x -> cnt ++;
	h=1;
      }
    }
    if (h == 0){
      one_count_t *x1 = NULL;
      x1 = malloc(sizeof(*x1));
      x1 -> str = malloc(strlen(name) + 8);
      strcpy(x1 -> str, name);
      x1 -> cnt = 1;
      c -> cntArr = realloc(c -> cntArr, (c -> cntSize + 1) * sizeof(*c -> cntArr));
      c -> cntArr[c -> cntSize] = x1;
      c -> cntSize ++;
    }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  one_count_t * x = NULL;
  for (size_t i = 0; i < c -> cntSize; i++){
    x = c->cntArr[i];
    fprintf(outFile, "%s: %zd\n", x -> str, x -> cnt);
  }
  if (c -> unknown != 0) fprintf(outFile, "<outFIle> : %zd\n", c -> unknown);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (size_t i = 0; i < c -> cntSize; i++){
    free(c -> cntArr[i] -> str);
    free(c -> cntArr[i]);
  }
  free(c -> cntArr);
  free(c);
}
