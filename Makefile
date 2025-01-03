MAKEFLAGS += --no-print-directory

# CORE

SRCDIR_CORE := $(PWD)/core
OUTDIR_CORE := $(PWD)/bin/core

core-lib:
	@mkdir -p $(OUTDIR_CORE)
	@make -f $(SRCDIR_CORE)/Makefile -C $(OUTDIR_CORE) seecorelib.a

core-test: core-lib
	@mkdir -p $(OUTDIR_CORE)
	@make -f $(SRCDIR_CORE)/Makefile -C $(OUTDIR_CORE) test
	$(OUTDIR_CORE)/test

# ---

FORMAT_OPTIONS := -kr -sob

format:
	@VERSION_CONTROL=never indent $(FORMAT_OPTIONS) `find -type f -regex ".+\.[c|h]"`
