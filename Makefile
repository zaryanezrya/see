MAKEFLAGS += --no-print-directory

# CORE

SRCDIR_CORE := $(PWD)/core
OUTDIR_CORE := $(PWD)/bin/core

core-lib:
	@mkdir -p $(OUTDIR_CORE)
	@make -f $(SRCDIR_CORE)/Makefile -C $(OUTDIR_CORE) libseecore.a

core-test: core-lib
	@mkdir -p $(OUTDIR_CORE)
	@make -f $(SRCDIR_CORE)/Makefile -C $(OUTDIR_CORE) test
	$(OUTDIR_CORE)/test

# ---

fmt:
	@clang-format -style=LLVM -i `find -type f -regex ".+\.[ch]"`
