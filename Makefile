#this is make file for building my sdl maze 
#the name of the output game will be "maze" may be I will change it in the future

CC = g++
LINKERFLAGS = -lSDL2 -lSDL2_image
CFLAGES = -Wall -Werror -Wextra -pedantic
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
NAME = mymaze
RM = rm


all: $(OBJ)
	echo $(SRC)
	echo $(OBJ)
	$(CC) $(OBJ) $(LINKERFLAGS) $(CFLAGES) -o $(NAME)

clean:
	-@$(RM) $(NAME) $(OBJ)

re: clean all

$(OBJ): def.h
