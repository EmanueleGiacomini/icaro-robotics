/**
  rescue_sensors.h
  Purpose: Interface with rescue robots of Icaro course

  @author Emanuele Giacomini
  @version 0.1 07/10/2017
*/
#ifndef vector_man_h
#define vector_man_h
#include <Arduino.h>

int* vecAlloc(const int size);
void vecWrite(int* src, const int size, const int val);
void vecWriteAt(int* src, const int size, const int index, const int val);
void vecFree(const int* src);
void vecSum(const int* src, const int size, int* dest);
void vecCopy(const int* src, const int size, int* dest);

// Arduino based functions.
void vecSetAsInput(const int* src, const int size);

#endif
