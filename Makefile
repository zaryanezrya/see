TEST_DIRS := $(shell find . -type d -name tests)

all:
    @echo "$(TEST_DIRS)"