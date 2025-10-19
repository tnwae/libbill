/*
 * Comparator functions for libbill.
 *
 * You have to pass pointers or addresses with these.  They're designed to be compatible with the standard library
 * functions @qsort@ and @bsearch@, which provide efficient sorting and searching.  You can hook these functions into
 * your own comparators to, for example, sort and search through structures.
 * 
 * $Id: compare.c 4 2012-10-25 15:00:30Z wae $
 */
#include <libbill.h>

int fcompare(const void *f1, const void *f2) {
  float *n1, *n2;
  n1 = (float*) f1;
  n2 = (float*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int ccompare(const void *f1, const void *f2) {
  char *n1, *n2;
  n1 = (char*) f1;
  n2 = (char*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int icompare(const void *f1, const void *f2) {
  int *n1, *n2;
  n1 = (int*) f1;
  n2 = (int*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int scompare(const void *f1, const void *f2) {
  short *n1, *n2;
  n1 = (short*) f1;
  n2 = (short*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int lcompare(const void *f1, const void *f2) {
  long *n1, *n2;
  n1 = (long*) f1;
  n2 = (long*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int llcompare(const void *f1, const void *f2) {
  long long *n1, *n2;
  n1 = (long long*) f1;
  n2 = (long long*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int dcompare(const void *f1, const void *f2) {
  double *n1, *n2;
  n1 = (double*) f1;
  n2 = (double*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

