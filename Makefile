# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 12:31:03 by asuikkan          #+#    #+#              #
#    Updated: 2021/11/03 13:07:02 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

LIB_NAME	= libft.a

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror -O3

SRC_DIR 	= ./
INC_DIR 	= ./includes
LIB_DIR 	= ./libft
LIB_INC 	= ./libft/includes

SRC 		= ft_anyitoa.c address.c ft_ftoa.c ft_printf.c ftoa_helper.c	\
			handlers1.c handlers2.c handlers3.c handlers4.c helpers.c		\
			modifiers1.c print.c

LIB_OBJ		= ft_strnew.o ft_strdup.o ft_strcat.o ft_strjoin.o ft_bzero.o	\
			ft_memset.o ft_memmove.o ft_count_digits.o ft_strlen.o			\
			ft_strdel.o ft_isdigit.o ft_memcpy.o ft_toupper.o

OBJ			= $(SRC:.c=.o) $(LIB_OBJ)

EXEC		= printf

all: $(NAME)

$(NAME):
	make -C $(LIB_DIR)
	ar -xv $(LIB_DIR)/$(LIB_NAME) $(LIB_OBJ)
	$(CC) $(FLAGS) -I $(INC_DIR) -I $(LIB_INC) -c $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

exec: $(NAME)
	$(CC) $(FLAGS) -I $(INC_DIR) main_test.c -o $(EXEC) -L ./ -lftprintf

eclean:
	rm -f $(EXEC)

.PHONY: all clean fclean re
