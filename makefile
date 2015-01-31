UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CC=g++ -std=c++14
endif
ifeq ($(UNAME), Darwin)
CC=g++-4.9 -std=c++14
#CC=clang++ -std=c++1y
endif

CFLAGS=-Ofast -lpthread -march=native -fomit-frame-pointer -flto -pipe

SRCDIR=src
OBJDIR=obj

_DEPS= point.h path.h
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ = main.o point.o path.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

all: main

test: debug

debug: CFLAGS = -DTIMING -ggdb -Wall -Wextra -O0 -lpthread
debug: main

main: $(OBJ)
	$(CC) $(CFLAGS) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cc $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

test:
	/bin/echo "10 pts:"
	./a.out < test/10.txt
	/bin/echo "100 pts:"
	./a.out < test/100.txt
	/bin/echo "1000 pts:"
	./a.out < test/1000.txt
	/bin/echo "1000 (Heavy) pts:"
	./a.out < test/1000heavy.txt

clean:
	rm -f a.out obj/*
