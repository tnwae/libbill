/*
 * Utility functions for libbill.  Includes creation and deletion of bstring, a slightly friendlier string type.
 *
 * $Id: libbill.c 4 2012-10-25 15:00:30Z wae $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <libbill.h>

static bool debugp;
static FILE *debug_out;
static bstring *version;

void libbill_init()
{
   atexit(libbill_cleanup);
   debugp = true;
   debug_out = stderr;
   version = bstring_create("libbill: this is version 0.1");
}

bstring *libbill_get_version() {
   return version;
}

void libbill_set_no_debug() {
  debugp = false;
}

void libbill_set_debug() {
  debugp = true;
  message("libbill: set debug mode to on\n");
}

void libbill_set_debug_output(char *path) {
  message("libbill: setting debug output to: %s\n", path);
  newhandle(debug_out, path, "w");
}

// For a given format string (printf-style) and argument list, print them out.
void message(const char *fmt, ...)
{
  if(debugp) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(debug_out, fmt, ap);
  }
  return;
}

// Clean up all the crud from the library.
void libbill_cleanup() {
  if(debug_out != stderr)
    fclose(debug_out);
  bstring_delete(version);
}

bstring *bstring_create(char *contents) {
  bstring *mystring = (bstring *) malloc(sizeof(bstring));
  mystring->contents = strdup(contents);
  mystring->length = strlen(contents);
  return mystring;
}

void bstring_delete(bstring *deleteme) {
  free(deleteme->contents);
  free(deleteme);
}
