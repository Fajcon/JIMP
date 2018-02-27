//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
  if (value >=13 or value <= -13) return 0;

  int result = 1;

  if (value<0){
    value=-value;
    if(value%2) result =-1;

  }

  for (;value>1;value--){
    result*=value;
  }
  return result;
}
