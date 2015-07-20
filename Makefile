# ---------------------------
# Makefile
#
# mlfong
# ---------------------------

SRCDIR  := source

SOURCES     := $(shell find $(SRCDIR) -name "*.cc")
CMD_SOURCES := $(SRCDIR)/main_cmdline.cc $(SRCDIR)/minesweeper.cc $(SRCDIR)/tile.cc
OBJECTS     := $(patsubst %.c, %.o, $(SOURCES))
CMD_OBJECTS := $(patsubst %.c, %.o, $(CMD_SOURCES))

CC      := clang++
CFLAGS  := -std=c++11 -pedantic -Wall -Werror -Weffc++ -Wextra -Wshadow -stdlib=libc++ -g

all: execme

cmdline: cmdexecme

execme: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o minesweeper

cmdexecme: $(CMD_OBJECTS)
	$(CC) $(CFLAGS) $^ -o minesweeper

clean:
	rm -rf *.out *.o minesweeper minesweeper.dSYM
