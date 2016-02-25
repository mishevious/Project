# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarguer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:35:34 by gmarguer          #+#    #+#              #
#    Updated: 2016/02/21 15:29:53 by gmarguer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

SRC = main.c parse.c error.c get_data.c sort.c ft_ls.c display.c 

OBJ = $(SRC:.c=.o)

INCLUDE = ft_ls.h

USER = gmarguer

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@echo "\033[2J"
	@echo "\033[100A"
	@make -C libft/
	@gcc $(FLAGS) -L./libft/ -lft -I $(INCLUDE) -o $(NAME) $(OBJ)
	@echo "\033[31m-\033[0m ls [\033[32mCOMPILE\033[0m]."
	@sleep 0.5

clean:
	@echo "\033[31m-\033[0m ls [\033[31mCLEAN\033[0m]."
	@rm -rf $(OBJ)
	@make clean -C libft/
	@sleep 0.5

fclean: clean
	@echo "\033[31m-\033[0m ls [\033[31mFCLEAN\033[0m]."
	@rm -rf $(NAME)
	@make fclean -C libft/
	@sleep 0.5

re: fclean all

check:
	@ls | grep -q auteur && cat -e auteur | grep -q $(USER)$ && echo \
	"Auteur [\033[32mOK\033[0m]" || echo "Auteur [\033[31mKO\033[0m]"
	@ls | grep -q -U $(NAME) && echo "$(NAME) [\033[32mOK\033[0m]" ||\
	echo "$(NAME) [\033[31mKO\033[0m]"
	@$(MAKE) norme | grep -B 1 Error && echo "Norme [\033[31mKO\033[0m]" || \
	echo "Norme [\033[32mOK\033[0m]"
	@ls $(LIB_PATH) | grep -q libft.a && echo "Libft [\033[32mOK\033[0m]" ||\
	echo "Libft [\033[31mKO\033[0m]"

norme:
	norminette *.[ch]

.PHONY: clean fclean re all norme auth verif
