SRCDIR := ./
OUTDIR := ./bin/

ioc.o: ioc.c ioc.h executable.h
	gcc -c ioc.c ioc.h

seeioclib.a: ioc.o
	ar rc seeioclib.a ioc.o
	ranlib seeioclib.a

test_ioc.o: test_ioc.c
	gcc -c test_ioc.c

test_ioc: test_ioc.o seeioclib.a
	gcc -o test_ioc test_ioc.o seeioclib.a
	./test_ioc
