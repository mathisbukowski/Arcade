##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

SRC = Core.cpp \
      DLManager.cpp \
      main.cpp \
      DLObject.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = $(DIR)/arcade

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++20 -fPIC -I$(INCLUDE_DIR)

LDFLAGS = -ldl

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all