#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned power_helper(unsigned x, unsigned y, unsigned ans){
  if (y == 0){
    return ans;
  }
  assert(x >= 0 && x < 42996729 && y > 0 && y < 4294967296);
  return power_helper(x, y -1, ans*x);
}

unsigned power(unsigned x, unsigned y){
  return power_helper(x,y,1);
}
