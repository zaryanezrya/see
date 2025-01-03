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

FORMAT_OPTIONS := 	-sai -npsl -nbc -brs -nfc1 -nprs -npcs -c33 -ce -cd33 \
					-nsc -bbo -nbad -br -bap -di1 -hnl -cli0 -ci4 -ip0 -d0 \
					-saw -saf -lp -nfca -cp33 -ncdb -sob -brf

format:
	@VERSION_CONTROL=never indent $(FORMAT_OPTIONS) `find -type f -regex ".+\.[c|h]"`
