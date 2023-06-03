CC=gcc

all: app

OBJS=app.o parser.o


app: $(OBJS)
	gcc -o $@ $^


clean:
	rm -f $(OBJS)
