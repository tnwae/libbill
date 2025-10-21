#ifndef _BSTRING_H_
#define _BSTRING_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _bstring {
  char *contents;
  unsigned int length;
} bstring;

typedef struct _bstring_builder {
  bstring *str;
  unsigned int capacity;
} bstring_builder;

bstring *bstring_create(char *);
void bstring_delete(bstring *);

// Get the C string out of a bstring.
#define BSTR(thestring) thestring->contents

#ifdef __cplusplus
}
#endif

#endif /* defined _BSTRING_H_ */
