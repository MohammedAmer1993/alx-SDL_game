#this is make file for building my sdl maze 
#the name of the output game will be "maze" may be I will change it in the future

CC = g++
LINKERFLAGS = -lSDL2
CFLAGES = 
SRC = maze.cpp
OBJ = $(SRC:.cpp=.o)
NAME = mymaze
RM = rm


all:
	$(CC) $(SRC) $(LINKERFLAGS) $(CFLAGES) -o $(NAME)

clean:
	-@$(RM) $(NAME) 

re: clean all
