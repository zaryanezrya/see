CC = gcc
CFLAGS = -I ./include -std=gnu99 -Wall -g -ggdb

DIR_OUT = $(PWD)/bin

# LIB

LIB_NAME = libSee
LIB_STATIC = $(DIR_OUT)/$(LIB_NAME).a

DIR_INC_LIB = $(PWD)/include

DIR_SRC_LIB = $(PWD)/src
SRC_LIB = $(wildcard $(DIR_SRC_LIB)/*.c)

DIR_OBJ_LIB = $(DIR_OUT)/libSee_obj
OBJ_LIB = $(addprefix $(DIR_OBJ_LIB)/,$(notdir $(SRC_LIB:.c=.o)))

$(LIB_STATIC): $(OBJ_LIB)
	$(AR) rcs $@ $(OBJ_LIB)

$(DIR_OBJ_LIB)/%.o: $(DIR_SRC_LIB)/%.c $(DIR_INC_LIB)/see.h
	@mkdir -p $(DIR_OBJ_LIB)
	$(CC) $< -c $(CFLAGS) -o $@

# GENERAL

clean:
	rm -rf $(DIR_OUT)

all: $(LIB_STATIC)


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
