# for (-j) use (# of CPU threads + 1), e.g. 9 for Core i7 920
MAKE=make

all: libbill

libbill:
	$(MAKE) -C src
	cp src/libbill.a .

clean:
	$(MAKE) -C src clean
	-rm libbill.a

