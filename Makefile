#this is make file for building my sdl maze 
#the name of the output game will be "maze" may be I will change it in the future

CC = g++
LINKERFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
CFLAGES = -Wall -Werror -Wextra -pedantic -I inc
CPPFLAGS = -Wall -Werror -Wextra -pedantic -I inc
TCFLAGES = 
TNAME = test
HEADERS = $(wildcard inc/*.h)
SRC = $(wildcard src/*.cpp)
SRC += main.cpp
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
	-@$(RM) $(OBJ)

clean: tclean oclean
	-@$(RM) $(NAME)

$(OBJ): $(HEADERS)

