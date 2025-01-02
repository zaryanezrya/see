SRCDIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

ioc.o: $(SRCDIR)ioc.c $(SRCDIR)ioc.h $(SRCDIR)executable.h
	gcc -c $(SRCDIR)ioc.c -o ioc.o

seecorelib.a: ioc.o
	ar rc seecorelib.a ioc.o
	ranlib seecorelib.a

test_core.o: $(SRCDIR)test_core.c
	gcc -c $(SRCDIR)test_core.c -o test_core.o

test_core: test_core.o seecorelib.a
	echo $(SRCDIR)
	gcc -o test_core test_core.o seecorelib.a
