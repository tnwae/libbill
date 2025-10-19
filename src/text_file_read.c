/*
 * $Id: text_file_read.c 4 2012-10-25 15:00:30Z wae $
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libbill.h>

/**
 * \brief Read a text file into a character string.
 *
 * This function blasts a text file into a character stream and returns
 * the stream as a pointer.
 *
 * @param path the path to read from
 * @return a string containing the contents of the file
 */
char *text_file_read(char *path)
{
   FILE *handle;
   char *contents = NULL;
   int size, count;

   newhandle(handle, path, "r");

   // how big is the file, portably
   fseek(handle, 0, SEEK_END);
   size = ftell(handle);
   rewind(handle);

   // if there's a file, load it
   if(0 < size) {
      newptr(contents, char, size + 1);
      count = fread(contents, sizeof(char), size, handle);
      contents[size] = '\0';
   }

   fclose(handle);
   return contents;
}

