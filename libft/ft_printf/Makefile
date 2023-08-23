# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 14:25:02 by lsabatie          #+#    #+#              #
#    Updated: 2023/01/26 12:27:29 by lsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
CC = gcc

SRC =   src/ft_printf.c\
		src/ft_putstr.c\
		src/ft_putnbr.c\
		src/ft_itoa_unsigned.c\
		src/ft_puthex.c\
		src/ft_toupper.c\
		src/ft_putptr.c\
		src/ft_itoa.c\
		src/ft_itoa_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c $(HEADER) Makefile
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) 

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re