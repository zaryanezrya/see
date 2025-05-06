SEE_SRCDIR := $(PWD)/src
SEE_BINDIR := $(PWD)/bin

core:
	@mkdir -p $(SEE_BINDIR)
	@make -f $(SEE_SRCDIR)/core/Makefile -C $(SEE_BINDIR) core

clean:
	rm -rf $(SEE_BINDIR)
