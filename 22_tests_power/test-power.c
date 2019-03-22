#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

int main(void){
  unsigned x = 2;
  unsigned n = 2;
  unsigned ans = 4;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 1;
  n = 2;
  ans = 1;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 2;
  n = 1;
  ans = 2;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 2;
  n = 31;
  ans = 2147483648;
  if (ans != power(x,n)){
    return EXIT_FAILURE;
  }
  x = 0;
  n = 2;
  ans = 0;
  if (ans != power(x,n)){
    return EXIT_FAILURE;
  }
  x = 1;
  n = -1;
  ans = 1;
  if (ans != power(x,n)){
    return EXIT_FAILURE;
  }
  x = 0;
  n = 0;
  ans = 1;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = -1;
  n = -1;
  ans = -1;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 1;
  n = -2;
  ans = 1;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 10;
  n = -2;
  ans = 0;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 'a';
  n = 2;
  ans = 9409;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  x = 2;
  n = 32;
  ans = 0;
  if (ans != power(x, n)){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
