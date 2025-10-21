#include <bstring.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _LBEXIT_H_
#define _LBEXIT_H_

typedef enum _lb_exit_code {
  LB_SUCCESS = 0,
  LB_FAIL_NOS = 1,
  LB_CONFIG = 20,
  LB_INTERNAL = 100,
  LB_MEMORY = 254,
  LB_IOERR = 255
} lb_exit_code;

extern bstring *lb_get_exit_string(lb_exit_code);

#ifdef __cplusplus
}
#endif

#endif /* defined _LBEXIT_H_ */

