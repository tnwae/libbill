/**
 * \file libbill.h
 *
 * Libbill is a personally written library designed to do functionality that I
 * deem useful.  These functionalities include the following:
 *
 * - Debug output handling.
 * - Comparison functions for use with qsort and bsearch.
 * - Facilities for preprocessing small input files to remove comments.
 *
 * The library is designed to be initialized prior to use and will eventually
 * clean up all of the memory associated with it at exit.
 * 
 * \author Bill Ellison
 * \version Alpha
 * \date 2011-04-06
 *
 * $Id: libbill.h 4 2012-10-25 15:00:30Z wae $
 */
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _LIBBILL_H_
#define _LIBBILL_H_

typedef struct _bstring {
  char *contents;
  unsigned int length;
} bstring;

//! @file libbill.c
void message(const char *fmt, ...);
//! @file libbill.c
void libbill_init();
//! @file libbill.c
void libbill_set_no_debug();
//! @file libbill.c
void libbill_set_debug();
//! @file libbill.c
void libbill_set_debug_output(char *);
//! @file libbill.c
void libbill_cleanup();
//! @file libbill.c
bstring *libbill_get_version();

//! @file text_file_preprocess.c
char *text_file_preprocess(char *file);
//! @file text_file_read.c
char *text_file_read(char *file);

//! @file compare.c
int fcompare(const void *, const void *);
//! @file compare.c
int dcompare(const void *, const void *);
//! @file compare.c
int icompare(const void *, const void *);
//! @file compare.c
int ccompare(const void *, const void *);
//! @file compare.c
int llcompare(const void *, const void *);
//! @file compare.c
int scompare(const void *, const void *);
//! @file compare.c
int lcompare(const void *, const void *);

//! @file text_file_read.c
char *text_file_read(char *);

//! @file libbill.c
bstring *bstring_create(char *);
//! @file libbill.c
void bstring_delete(bstring *);

// Get the C string out of a bstring.
#define BSTR(thestring) thestring->contents

// Create a new pointer.  You specify the variable, its type, and the number of those
// objects you want.  If creation fails, the program exits.  if you don't want this
// behavior, write it out longhand.  By default, perror specifies where the error occurred
// so you can more easily debug.
#define newptr(variable, type, amount) \
   variable = (type*) malloc(sizeof(type) * amount);	\
   if(variable == NULL) { \
     perror(__FUNCTION__); \
     exit(EXIT_FAILURE); \
   }

// Create a new FILE handle.  You specify the variable, the filename, and the mode for
// fopen.  If creating the file handle fails, the program exits.  If you don't want this
// behavior, write it out longhand.  By default, perror specifies where the error occurred
// so you can more easily debug.
#define newhandle(variable, where, mode)		\
   variable = fopen(where, mode); \
   if(variable == NULL) { \
     perror(__FUNCTION__); \
     exit(EXIT_FAILURE); \
   }

#ifdef __cplusplus
}
#endif

#endif /* defined _LIBBILL_H_ */

