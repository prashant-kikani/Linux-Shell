SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HDR = $(SRC:.c=.h)
CC = gcc
EXEC = myshell

all:$(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $^ -o $@

%.o : %.c %.h
	$(CC) -c $<

#.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)
