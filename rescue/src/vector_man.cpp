/**
  vector_man.cpp
  Purpose: Vector manipulation functions, useful for every situation =)

  @author Emanuele Giacomini
  @version 0.1 07/10/2017
*/

#include "vector_man.h"

int* vecAlloc(const int size){
  return (int*) malloc(sizeof(int)*size);
}

void vecWrite(int* src, const int size, const int val){
  for(int i = 0; i < size; i++){
    src[i] = val;
  }
}

void vecWriteAt(int* src, const int size, const int index, const int val){
    if(index >= 0 && index < size){
      src[index] = val;
    }
}

void vecSum(const int* src, const int size, int* dest){
  for(int i = 0; i < size; i++){
    dest[i] += src[i];
  }
}

void vecSetAsInput(const int* src, const int size){
  for(int i = 0; i < size; i++){
    pinMode(src[i], INPUT);
  }
}
