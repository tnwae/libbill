/*
 * Utility functions for libbill.  Includes creation and deletion of bstring, a slightly
 * friendlier string type.
 *
 * $Id: libbill.c 4 2012-10-25 15:00:30Z wae $
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <execinfo.h>
#include <libbill.h>
#include <lbexit.h>

static bool debugp;
static FILE *debug_out;
static bstring *version;
lb_exit_code lb_exit_status;

void libbill_init(void)
{
   atexit(libbill_cleanup);
   atexit(libbill_backtrace);
   atexit(libbill_friendly_exit);
   debug_out = stderr;
   libbill_set_debug();
   version = bstring_create("0.2");
}

bstring *libbill_get_version(void)
{
   return version;
}

void libbill_set_no_debug(void)
{
  message("libbill: set debug mode to off\n");
  debugp = false;
}

void libbill_set_debug(void)
{
  debugp = true;
  message("libbill: set debug mode to on\n");
}

void libbill_set_debug_output(char *path)
{
  message("libbill: setting debug output to: %s\n", path);
  debug_out = fopen(path, "w");
  if(debug_out == NULL) {
    perror(__func__);
    depart(254);
  }
}

void libbill_backtrace(void)
{
  if(debugp && lb_exit_status != LB_SUCCESS) {
    void *array[32];
    int size = backtrace(array, 32);
    char **symbols = backtrace_symbols(array, size);
    if(symbols == NULL) {
      return;
    }

    for(int i = 0; i < size; i++) {
      message("%s\n", symbols[i]);
    }

    free(symbols);
  }

  return;
}

void libbill_friendly_exit(void)
{
  if(debugp) {
    message("libbill: %s\n", BSTR(lb_get_exit_string(lb_exit_status)));
  }
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
void libbill_cleanup(void) {
  if(debug_out != stderr)
    fclose(debug_out);
  bstring_delete(version);
}
