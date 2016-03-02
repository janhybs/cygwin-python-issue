# get flags from python config
ldflags27=$(shell python2.7-config --ldflags)
cflags27=$(shell  python2.7-config --cflags)

ldflags34=$(shell python3.4m-config --ldflags)
cflags34=$(shell  python3.4m-config --cflags)

# python2.7

.PHONY : all27
all27: link27
	echo "--running"
	./output/embedpy27

.PHONY : link27
link27: compile27
	echo "--linking"
	gcc ./output/embedpy27.o $(ldflags27) -lstdc++ -o ./output/embedpy27 

.PHONY : compile27
compile27:
	echo "--compiling"
	gcc -c $(cflags27) -lstdc++ embedpy.cc -o ./output/embedpy27.o

.PHONY : ldd27
ldd27: all27
	ldd ./output/embedpy27

# python 3.4m

.PHONY : all34
all34: link34
	echo "--running"
	./output/embedpy34

.PHONY : link34
link34: compile34
	echo "--linking"
	gcc ./output/embedpy34.o $(ldflags34) -lstdc++ -o ./output/embedpy34 

.PHONY : compile34
compile34:
	echo "--compiling"
	gcc -c $(cflags34) -lstdc++ embedpy.cc -o ./output/embedpy34.o

.PHONY : ldd34
ldd34: all34
	ldd ./output/embedpy34