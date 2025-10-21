#include <stdlib.h>
#include <string.h>
#include <bstring.h>

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
