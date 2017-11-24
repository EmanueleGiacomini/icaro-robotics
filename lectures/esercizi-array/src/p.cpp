#include "p.h"

int vec_getElem(int vec[], int i) {
  return vec[i];
}
void vec_writeElem(int vec[], int i, int n) {
  vec[i] = n;
}
void vec_write(int vec[], int dim, int n) {
  for(int i = 0; i < dim; i++) vec[i] = n;
}
void vec_findElem(int vec[], int dim, int n) {
  for(int i = 0; i < dim; i++) {
    if(vec[i] == n) return 1;
  }
  return 0;
}
