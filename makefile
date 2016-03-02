# get flags from python config
ldflags=$(shell /usr/bin/python2.7-config --ldflags)
cflags=$(shell python2.7-config --cflags)


.PHONY : all
all: link
	echo "--running"
	./output/embedpy

.PHONY : link
link: compile
	echo "--linking"
	gcc ./output/embedpy.o $(ldflags) -lstdc++ -o ./output/embedpy 

.PHONY : compile
compile:
	echo "--compiling"
	gcc -c $(cflags) -lstdc++ embedpy.cc -o ./output/embedpy.o

.PHONY : ldd
ldd: all
	ldd ./output/embedpy