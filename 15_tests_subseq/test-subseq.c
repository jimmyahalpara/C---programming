#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

int test(int *ar, size_t size, size_t correct){
  if (maxSeq(ar,size) != correct){
    exit(EXIT_FAILURE);
  }}

int main(){
  int array1[] = {1,2,3,4};
  test(array1,4,4);
  int array2[] = {4,3,2,1};
  test(array2,4,1);
  int array3[] = {1,2,3,4,5,5,6,7};
  test(array3, 8,5);
  int array4[] = {2};
  test(array4,1,1);
  int array5[] = {1,-5,-4,-3};
  test(array5, 4, 3);
  int array6[] = {};
  test(array6,0,0);
  return(EXIT_SUCCESS);
}
