NAME = fixed

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -g

SRC_DIR = srcs
OBJ_DIR = objs

SRC = srcs/main.cpp srcs/Fixed.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

%.o:%.c
	$(CC) $(SRC) $(CFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
