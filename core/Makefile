SRCDIR := .
OUTDIR := .

ioc.o: $(SRCDIR)/ioc.c $(SRCDIR)/ioc.h $(SRCDIR)/executable.h
	gcc -c $(SRCDIR)/ioc.c -o $(OUTDIR)/ioc.o

seecorelib.a: ioc.o
	ar rc $(OUTDIR)/seecorelib.a $(OUTDIR)/ioc.o
	ranlib $(OUTDIR)/seecorelib.a

test_core.o: test_core.c
	gcc -c $(SRCDIR)/test_core.c -o $(OUTDIR)/test_core.o

test_core: test_core.o seecorelib.a
	gcc -o $(OUTDIR)/test_core $(OUTDIR)/test_core.o $(OUTDIR)/seecorelib.a
