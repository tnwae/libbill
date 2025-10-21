#include <stdlib.h>
#include <lbexit.h>
#include <bstring.h>

extern int lb_exit_status;

/**
 * depart
 * ======
 *     Exits the program while setting an indicated exit status for the use of
 *     `atexit()` handlers invoked during exit.
 * 
 *     Warning: Modifies global state variable `lb_exit_status`.
 * 
 * Parameters
 * ----------
 * status : int
 *     The desired exit code.
 */
void depart(int status) {
   lb_exit_status = status;
   exit(lb_exit_status);
}

/**
 * lb_get_exit_string
 * ==================
 * 
 * Parameters
 * ----------
 * exit_code : lb_exit_code
 *     The exit code to describe with a string.
 * 
 * Returns
 * -------
 * bstring
 *     A string containing a friendly description of the exit code.
 */
bstring *lb_get_exit_string(lb_exit_code exit_code)
{
  bstring *str;

  switch(exit_code) {
    case LB_SUCCESS:
      str = bstring_create("program exited successfully");
      break;
    case LB_FAIL_NOS:
      str = bstring_create("execution failed");
      break;
    case LB_CONFIG:
      str = bstring_create("configuration error");
      break;
    case LB_INTERNAL:
      str = bstring_create("internal error");
      break;
    case LB_MEMORY:
      str = bstring_create("out of memory");
      break;
    case LB_IOERR:
      str = bstring_create("I/O error");
      break;
  }

  return str;
}

