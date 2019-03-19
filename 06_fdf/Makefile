#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 11:18:28 by qbenaroc          #+#    #+#              #
#    Updated: 2019/03/05 23:23:47 by qbenaroc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Binary

NAME = fdf

	# Flags

FLAGS = -Wall -Wextra -Werror
CC = gcc
MLX = ./minilibx_macos/libmlx.a -framework OpenGL -framework Appkit

	# Paths

HEADER_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

	# Files

SRC_FILES = main.c					\
			ft_check_file.c			\
			ft_fdf.c				\
			ft_create_map.c			\
			ft_mlx.c				\
			ft_key_hook.c			\
			ft_refresh_img.c		\
			ft_close.c				\
			ft_draw.c				\
			ft_bresenham.c			\
			ft_put_pixel_to_img.c	\
			ft_color.c				\
			ft_select_points.c		\
			ft_cam.c				\
			ft_hud.c

LIB_FILE = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_FILE))

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

	# Rules

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH)includes/ -I $(MLX_PATH)
	@echo "\033[1;34mCompilation of \033[36m$(notdir $<)\033[0m \033[32mdone\033[0m"

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
	@$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) $(MLX) -o $@ -I $(HEADER_PATH)
	@echo "\033[1;32mFdf\t\t\033[0;32m[Compilation done]\033[0;32m"

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[1;32mfdf\t\t\033[1;31m[.o removed]"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "\033[1;32mfdf\t\t\033[1;31m[Executable removed]"

re: fclean all

.PHONY: all, clean, fclean, re
