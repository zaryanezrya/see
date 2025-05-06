SEE_SRCDIR := $(PWD)/src
SEE_BINDIR := $(PWD)/bin
SEE_PLUGINSDIR := $(SEE_SRCDIR)/plugins

SEE_PLUGINS := hello_world

core:
	@mkdir -p $(SEE_BINDIR)
	@make -f $(SEE_SRCDIR)/core/Makefile -C $(SEE_BINDIR) core

plugins:
	@for plugin in $(SEE_PLUGINS) ; do \
		echo $$plugin ; \
	done

clean:
	rm -rf $(SEE_BINDIR)
