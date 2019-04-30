#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int checkinput(FILE * f){
  int c = 0;
  int col = 0;
  c = fgetc(f);
  while (!(c == EOF)){
    for(int i = 0;  i < 10; i++){
      if (c == '\n'){
	fprintf(stderr, "char error");
	return 0;
      }
      c = fgetc(f);
    }
    if (c != '\n'){
      fprintf(stderr, "row err");
      return 0;
    }
    c = fgetc(f);
    col++;
  }
  if (col == 10) return 1;
  else {
    fprintf(stderr, "column err");
    return 0;
  }
}

void rotate(int  matrix[10][10]){
  for (int i = 0; i<10; i++){
    for (int j = 10-1; j >= 0; j--){
      printf("%c", matrix[j][i]);
    }
    printf("\n");
  }
}

int main(int argc, char** argv){
  if (argc != 2){
    fprintf(stderr, "not correct number of argument \n");
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  if (!(checkinput(f))) return EXIT_FAILURE;
  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int  matrix[10][10];
  int c = 0;
  for (int i = 0; i < 10; i++){
    for (int  j = 0; j < 10; j++){
      c = fgetc(f);
      if (c == '\n') c = fgetc(f);
      matrix[i][j] = c;
    }
  }
  rotate(matrix);
  if (fclose(f) != 0){
    perror("Failed to close the input file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
