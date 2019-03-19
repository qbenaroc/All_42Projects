# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 16:18:57 by qbenaroc          #+#    #+#              #
#    Updated: 2019/01/16 11:46:52 by qbenaroc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./fillit

FLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c				\
			read.c				\
			check.c				\
			tetrimino.c			\
			check_maps.c		\
			array.c				\
			array_values.c		\
			map.c				\
			solve.c

HEADER_PATH = ./includes/
LIB_PATH = ./libft/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

LIB_FILES = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH)includes/
	@echo "\033[1;34mCompilation of \033[36m$(notdir $<)\033[0m \033[32mdone\033[0m"

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
	@gcc $(FLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(HEADER_PATH)
	@echo "\033[1;32mFillit\t\t\033[0;32m[Compilation done]\033[0;32m"

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[1;32mFillit\t\t\033[1;31m[.o removed]"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -rf $(NAME)
	@echo "\033[1;32mFillit\t\t\033[1;31m[Executable removed]"

re: fclean all
