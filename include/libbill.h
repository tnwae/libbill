/**
 * \file libbill.h
 *
 * Libbill is a personally written library designed to do functionality that I
 * deem useful.  These functionalities include the following:
 *
 * - Debug output handling.
 * - Comparison functions for use with qsort and bsearch.
 * - Facilities for preprocessing small input files to remove comments.
 * - Linked lists
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
#include <bstring.h>
#include <blist.h>
#include <execinfo.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _LIBBILL_H_
#define _LIBBILL_H_

void depart(int);
void message(const char *fmt, ...);
void libbill_init(void);
void libbill_set_no_debug(void);
void libbill_set_debug(void);
void libbill_set_debug_output(char *);
void libbill_cleanup(void);
bstring *libbill_get_version(void);
void libbill_backtrace(void);
void libbill_friendly_exit(void);

char *text_file_preprocess(char *file);
char *text_file_read(char *file);

int fcompare(const void *, const void *);
int dcompare(const void *, const void *);
int icompare(const void *, const void *);
int ccompare(const void *, const void *);
int llcompare(const void *, const void *);
int scompare(const void *, const void *);
int lcompare(const void *, const void *);

#ifdef __cplusplus
}
#endif

#endif /* defined _LIBBILL_H_ */
