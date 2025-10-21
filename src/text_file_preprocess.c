/*
 * $Id: text_file_preprocess.c 4 2012-10-25 15:00:30Z wae $
 */

#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <libbill.h>

/**
 * \brief Preprocess a text file, removing commented lines from the file.
 *
 * Maximal line length is 1024 characters.  This function removes blank
 * lines and commented lines with a #.
 *
 * The only limitation is that multicharacter comment characters don't
 * work and end-of-line comments aren't handled.
 * @param file the file's path name to read from
 * @return A character stream with the preprocessed file in it.  The caller is
 * responsible for freeing the memory associated with the stream.
 */
char *text_file_preprocess(char *file)
{
  char *contents = NULL, *line;
  int size, offset = 0, skipped = 0, lines = 0;
  FILE *handle;

  handle = fopen(file, "r");
  if(handle == NULL)
    return NULL;

  line = (char*) malloc(sizeof(char) * 1024);
  if(line == NULL) {
    perror(__func__);
    depart(255);
  }

  // how big is the file, portably
  fseek(handle, 0, SEEK_END);
  size = ftell(handle);
  rewind(handle);

  // if there's a file, load it selectively with the wonders of grep
  if(size > 0) {
    contents = (char*) malloc(sizeof(char) * (size + 1));
    if(contents == NULL) {
      perror(__func__);
      depart(255);
    }
    memset(contents, 0, size + 1);

    for(;;) {
      memset(line, 0, 1024);
      char *ptr = fgets(line, 1024, handle);

      if(ptr != NULL) {
        int len = strlen(line);
        ++lines;
        // if the line starts with a comment or is empty, don't load it
        // otherwise, do load it
        switch(line[0]) {
          case '#':
          case ';':
          case '\n':
            ++skipped;
            break;
          default:
            // the following line is bad and i should feel bad
            strncat(contents, line, len);
            offset += len;
            break;
        }
      } else break;
    }
    contents[offset+1] = '\0';
  }
  fclose(handle);
  free(line);
  return contents;
}

