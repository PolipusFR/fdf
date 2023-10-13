# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 19:21:06 by lsabatie          #+#    #+#              #
#    Updated: 2023/10/13 16:16:45 by lsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := fdf
CC       := gcc
FLAGS    := -Wall -Wextra -Werror -O3
HEADER   := includes/fdf.h

SRCS        :=      utils/ft_atoi.c \
                        utils/ft_split.c \
                        utils/ft_strcmp.c \
                        utils/get_next_line.c \
                        utils/get_next_line_utils.c \
                        utils/ft_printf/ft_printf.c \
                        utils/ft_printf/pf_itoa.c \
                        utils/ft_printf/pf_itoa_utils.c \
                        utils/ft_printf/pf_itoa_unsigned.c \
                        utils/ft_printf/pf_puthex.c \
                        utils/ft_printf/pf_putnbr.c \
                        utils/ft_printf/pf_putptr.c \
                        utils/ft_printf/pf_putstr.c \
                        utils/ft_printf/pf_toupper.c \
                        src/main.c \
                        src/main_utils.c \
                        src/read_file.c \
                        src/draw.c \
                        src/read_file_utils.c \
                        src/draw_utils.c \
                          
OBJS        := $(SRCS:.c=.o)

%.o:%.c $(HEADER) Makefile
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
			chmod 777 mlx_linux/configure
			$(MAKE) -C mlx_linux all
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm


all:		${NAME}

clean:
			${RM} *.o */*.o */*/*.o
			rm -rf $(NAME).dSYM >/dev/null 2>&1

fclean:		clean
			${RM} ${NAME}
			$(MAKE) -C mlx_linux clean 

re:			fclean all

.PHONY:		all clean fclean re
