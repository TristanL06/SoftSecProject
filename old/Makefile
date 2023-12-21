CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -Wl,-rpath=.

SRC_FILES = main.c client.c server.c
OBJ_FILES = $(SRC_FILES:.c=.o)

LIBS = -L. -lclient -L. -lserver

my_program: $(OBJ_FILES) client.o server.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

run: my_program
	./my_program

client.o: client.c client.h
	$(CC) $(CFLAGS) -c -o $@ $<

server.o: server.c server.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) my_program
