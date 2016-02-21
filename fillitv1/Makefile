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

NAME = fillit
SRC  = `ls | grep "\.c"`
OBJ  = `ls | grep "\.o"`
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

.PHONY: clean fclean re
