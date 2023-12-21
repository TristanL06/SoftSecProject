CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -I. -L.

SRC_FILES = init.c
OBJ_FILES = $(SRC_FILES:.c=.o)

LIBS = -lclient -lserver

my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) my_program
