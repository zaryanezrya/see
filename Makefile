CC = gcc
CFLAGS = -I ./include -std=gnu99 -Wall -g -ggdb

NAME = libSee
VERSION = 0.0.1
PACKAGE = libSee-${VERSION}

INCDIR = ${PWD}/include

BINDIR = ${PWD}/bin
STATIC = ${NAME}.a
DYNAMIC = ${NAME}.so

SRC := $(wildcard src/*.c) $(wildcard src/core/*.c)
OBJ := $(addprefix $(BINDIR)/obj/,$(notdir $(SRC:.c=.o)))


all: $(STATIC)
# all: $(DYNAMIC) $(STATIC)


clean:
	rm -rf $(BINDIR)

${STATIC}: $(OBJ)
	@echo $(AR) rcs $@ $(SRC)



libSee_obj:
	mkdir -p $(BINDIR)/libSee_obj


# /bin
# 	/libSee.a
# 	/libSee.so
# 	/libSee_obj
#	/libSee_modules
#	/libSee_modules_obj







# SEE_SRCDIR := $(PWD)/src
# SEE_BINDIR := $(PWD)/bin
# SEE_MODULESDIR := $(SEE_SRCDIR)/modules

# SEE_MODULES := hello_world

# core:
# 	@mkdir -p $(SEE_BINDIR)
# 	@make -f $(SEE_SRCDIR)/core/Makefile -C $(SEE_BINDIR) core

# modules:
# 	@mkdir -p $(SEE_BINDIR)/modules
# 	@for module in $(SEE_MODULES) ; do \
# 		echo make -f $(SEE_MODULESDIR)/$$module/Makefile -C $(SEE_BINDIR)/modules module \
# 		# echo $$module ; \
# 	done

# clean:
# 	rm -rf $(SEE_BINDIR)
