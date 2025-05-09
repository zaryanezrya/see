CC = gcc
CFLAGS = -I ./include -std=gnu99 -Wall -g -ggdb

NAME = libSee

INCDIR = $(PWD)/include

BINDIR = $(PWD)/bin
LIB_STATIC = $(BINDIR)/$(NAME).a

LIB_SRC := $(wildcard src/*.c)
OBJ := $(addprefix $(BINDIR)/libSee_obj/,$(notdir $(LIB_SRC:.c=.o)))


all: $(LIB_STATIC)


clean:
	rm -rf $(BINDIR)

$(LIB_STATIC): $(OBJ)
	$(AR) rcs $@ $(OBJ)

$(BINDIR)/libSee_obj/%.o: src/%.c include/see.h
	@mkdir -p $(BINDIR)/libSee_obj
	$(CC) $< -c $(CFLAGS) -o $@



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
