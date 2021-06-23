CC = gcc
FLAGS = -LSDL `sdl2-config --cflags --libs` -lm
EXEC = prog
SRC = $(wildcard *.c src/*.c )
OBJ = $(SRC:.c=.o)

all: $(EXEC)

%.o : %.c
		$(CC) -o $@ -c $< $(FLAGS)

$(EXEC) : $(OBJ)
		$(CC) -o $@ $^ $(FLAGS)

clean :
		rm -rf src/*.o

mrproper : clean
		rm -rf $(EXEC)

run :
		./$(EXEC)

makeAndRun : all run
