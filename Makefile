SEE_SRCDIR := $(PWD)/src
SEE_BINDIR := $(PWD)/bin
SEE_MODULESDIR := $(SEE_SRCDIR)/modules

SEE_MODULES := hello_world

core:
	@mkdir -p $(SEE_BINDIR)
	@make -f $(SEE_SRCDIR)/core/Makefile -C $(SEE_BINDIR) core

modules:
	@for module in $(SEE_MODULES) ; do \
		echo $$module ; \
	done

clean:
	rm -rf $(SEE_BINDIR)
