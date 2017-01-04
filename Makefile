# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efichot <efichot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 12:57:23 by efichot           #+#    #+#              #
#    Updated: 2016/12/14 14:47:49 by efichot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = arg_and_utils.c axone.c color_and_pixel.c custom.c fractol.c init.c \
	julia.c key_hook.c mandelbrot.c burningship.c newton.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./libft -lft

CC = gcc

INCLUDES = ./includes

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDES)  $(FLAGSMLX) $(LIBFT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
