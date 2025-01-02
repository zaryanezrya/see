OUTDIR := ./bin/

# --- CORE

CORE_SRCDIR	:= core
CORE_SRC 	:= $(CORE_SRCDIR)/ioc.c $(CORE_SRCDIR)/ioc.h $(CORE_SRCDIR)/executable.h
CORE_LIB 	:= seecorelib.a
CORE_TEST	:= seecoretest


seeioclib.a: $(CORE_SRC)
	gcc -c $(CORE_SRC) -o $(OUTDIR)
	ar rc seeioclib.a ioc.o
	ranlib seeioclib.a

test_ioc.o: test_ioc.c
	gcc -c test_ioc.c

test_core: test_ioc.o seeioclib.a
	gcc -o test_ioc test_ioc.o seeioclib.a
	./test_ioc
