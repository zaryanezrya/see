# CORE

SRCDIR_CORE := $(PWD)/core
OUTDIR_CORE := $(PWD)/bin/core

test_core:
	@mkdir -p $(OUTDIR_CORE)
	@make -f $(SRCDIR_CORE)/Makefile -C $(OUTDIR_CORE) test_core
	$(OUTDIR_CORE)/test_core

# ---

FORMAT_OPTIONS := -kr -sob

format:
	@VERSION_CONTROL=never indent $(FORMAT_OPTIONS) `find -type f -regex ".+\.[c|h]"`
