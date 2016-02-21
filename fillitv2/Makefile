# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2015/12/11 13:04:28 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =	fillit

SRC  =	fillit.c ft_create.c ft_dep_resolve.c ft_inter.c ft_item.c \
		ft_open.c ft_parse.c ft_read.c ft_resolve.c ft_square.c \
		ft_strlen.c ft_strnew.c ft_strsub.c ft_write_square.c \
		main.c

OBJ  = $(SRC:.c=.o)

FLAGS =  -Wall -Wextra -Werror

INCLUDE = fillit.h

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -I$(INCLUDE) -c $(SRC)
		@gcc $(FLAGS) -o $(NAME) $(OBJ)
		@echo "-------\033[36mCompilation programme\033[0m-------"

clean:
		@echo "----------\033[31mSuppression .o\033[0m-----------"
		@rm -rf $(OBJ)

fclean: clean
		@echo "-------\033[31mSuppression programme\033[0m-------"
		@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
