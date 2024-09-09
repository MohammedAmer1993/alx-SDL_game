#this is make file for building my sdl maze 
#the name of the output game will be "maze" may be I will change it in the future

CC = g++
LINKERFLAGS = -lSDL2 -lSDL2_image
CFLAGES = -Wall -Werror -Wextra -pedantic
TCFLAGES = 
TNAME = test
SRC = $(wildcard *.cpp)
OBJ = $(filter-out test.o, $(SRC:.cpp=.o))
NAME = maze
RM = rm

.PHONY: debug all clean re tclean test

all: $(OBJ)
	$(CC) $(OBJ) $(LINKERFLAGS) $(CFLAGES) -o $(NAME)

re: oclean all

debug: oclean $(OBJ)
	$(CC) $(OBJ) $(LINKERFLAGS) $(CFLAGES) -g -o $(NAME)


test: 
	$(CC) test.cpp $(LINKERFLAGS) $(TCFLAGES) -o $(TNAME)

tclean: 
	-@$(RM) test test.o

oclean:
	-@$(RM) $(NAME) $(OBJ)

clean: tclean oclean

$(OBJ): def.h

