SRCDIR := 
OUTDIR := 

ioc.o: ioc.c ioc.h executable.h
	gcc -c ioc.c ioc.h

seeioclib.a: ioc.o
	ar rc seeioclib.a ioc.o
	ranlib seeioclib.a

test_core.o: test_core.c
	gcc -c test_core.c

test_core: test_core.o seeioclib.a
	gcc -o test_core test_core.o seeioclib.a
	./test_core
