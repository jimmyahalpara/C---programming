#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n){
  size_t size = 0;
  if (array == NULL || n <= 0){
    return size;
  }
  if (n<=2 && n>0){
    return n;
  }
  if (n >= 2){
    for (int i = 0; i<n; i++){
      size_t ans_temp = 0;
      for (int j = 0; j<n; j++){
	if (j != 0){
	  if (array[j]>array[j-1]){
	    ans_temp++;
	  }
	  else{
	    break;
	  }
	}
      }
      if (ans_temp > size){
	size = ans_temp;
      }
    }
  }
  return size;
}

int main(){
  return EXIT_SUCCESS;
}
