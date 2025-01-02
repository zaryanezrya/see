SRCDIR := .
OUTDIR := .

$(OUTDIR)/ioc.o: $(SRCDIR)/ioc.c $(SRCDIR)/ioc.h $(SRCDIR)/executable.h
	gcc -c $(SRCDIR)/ioc.c -o $(OUTDIR)/ioc.o

$(OUTDIR)/seecorelib.a: $(OUTDIR)/ioc.o
	ar rc $(OUTDIR)/seecorelib.a $(OUTDIR)/ioc.o
	ranlib $(OUTDIR)/seecorelib.a

$(OUTDIR)/test_core.o: test_core.c
	gcc -c $(SRCDIR)/test_core.c -o $(OUTDIR)/test_core.o

$(OUTDIR)/test_core: $(OUTDIR)/test_core.o $(OUTDIR)/seecorelib.a
	gcc -o $(OUTDIR)/test_core $(OUTDIR)/test_core.o $(OUTDIR)/seecorelib.a
