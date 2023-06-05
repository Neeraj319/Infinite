CC=gcc

CPPFLAGS=-g
LDFLAGS=-g

all: app

OBJS=app.o parser.o vector.o


app: $(OBJS)
	gcc -o $@ $^ -g -OO

check_leaks:
	valgrind --leak-check=full ./app $(f)

clean:
	rm -f $(OBJS)
