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

   handle = fopen(path, "r");
   if(handle == NULL) {
     message("failed reading file %s\n", path);
     perror(__func__);
     depart(254);
   }

   // how big is the file, portably
   fseek(handle, 0, SEEK_END);
   size = ftell(handle);
   rewind(handle);

   // if there's a file, load it
   if(0 < size) {
      contents = (char*) malloc(sizeof(char) * (size + 1));
      if(contents == NULL) {
        perror(__func__);
        depart(255);
      }

      count = fread(contents, sizeof(char), size, handle);
      message("%s: read %d bytes from %s\n", __func__, count, path);
      contents[size] = '\0';
   }

   fclose(handle);
   return contents;
}

