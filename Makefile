SRCDIR_CORE := $(PWD)/core
OUTDIR_CORE := $(PWD)/bin/core


test_core:
	mkdir -p $(OUTDIR_CORE)
	make -C $(SRCDIR_CORE) OUTDIR=$(OUTDIR_CORE) $(OUTDIR_CORE)/test_core
	$(OUTDIR_CORE)/test_core