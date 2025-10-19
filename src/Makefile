CFLAGS = -Wall -Wextra -pedantic -std=gnu99 -g -I../include -m64

all: libbill.a

OBJS = libbill.o text_file_preprocess.o compare.o text_file_read.o

docs:
	doxygen Doxyfile

libbill.a: $(OBJS)
	ar ru libbill.a $(OBJS)
	ranlib libbill.a 
	cp libbill.a ../..

clean:
	-rm -f core *.o libbill.a

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

