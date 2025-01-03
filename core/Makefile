SRCDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

executable.o: $(SRCDIR)executable.c $(SRCDIR)executable.h
	gcc -c $(SRCDIR)executable.c -o executable.o

ioc.o: $(SRCDIR)ioc.c $(SRCDIR)ioc.h 
	gcc -c $(SRCDIR)ioc.c -o ioc.o

libseecore.a: ioc.o executable.o
	ar rc libseecore.a ioc.o executable.o
	ranlib libseecore.a

test_core.o: $(SRCDIR)test_core.c
	gcc -c $(SRCDIR)test_core.c -o test_core.o

test: test_core.o libseecore.a
	gcc -static -o test test_core.o libseecore.a
