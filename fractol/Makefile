# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:35:34 by gmarguer          #+#    #+#              #
#    Updated: 2016/02/23 22:25:29 by gmarguer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC =	main.c error.c draw.c ark.c\
		color.c hook.c load.c julia.c\
		mandelbrot.c newton.c

OBJ = $(SRC:.c=.o)

FLAGS =  -Wall -Wextra -Werror

INCLUDE = fractol.h

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[2J"
	@echo "\033[100A"
	@make -C libft/
	@gcc $(FLAGS) -L./libft/ -lft -I $(INCLUDE) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[31m-\033[0m FRACTOL [\033[32mCOMPILE\033[0m]."
	@sleep 0.5

clean:
	@rm -rf $(OBJ)
	@make clean -C libft/
	@echo "\033[31m-\033[0m FRACTOL [\033[31mCLEAN\033[0m]."
	@sleep 0.5

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@echo "\033[31m-\033[0m FRACTOL [\033[31mFCLEAN\033[0m]."
	@sleep 0.5

re: fclean all

.PHONY: clean fclean re all
