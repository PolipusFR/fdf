# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 19:21:06 by lsabatie          #+#    #+#              #
#    Updated: 2023/10/12 22:24:15 by lsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fdf
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g3

SRCS        :=      libft/ft_atoi.c \
                          libft/ft_bzero.c \
                          libft/ft_calloc.c \
                          libft/ft_isalnum.c \
                          libft/ft_isalpha.c \
                          libft/ft_isascii.c \
                          libft/ft_isdigit.c \
                          libft/ft_isprint.c \
                          libft/ft_itoa.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_lstclear.c \
                          libft/ft_lstdelone.c \
                          libft/ft_lstiter.c \
                          libft/ft_lstlast.c \
                          libft/ft_lstnew.c \
                          libft/ft_lstsize.c \
                          libft/ft_memchr.c \
                          libft/ft_memcmp.c \
                          libft/ft_memcpy.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_printf/src/ft_printf.c \
                          libft/ft_printf/src/pf_itoa.c \
                          libft/ft_printf/src/pf_itoa_unsigned.c \
                          libft/ft_printf/src/pf_itoa_utils.c \
                          libft/ft_printf/src/pf_puthex.c \
                          libft/ft_printf/src/pf_putnbr.c \
                          libft/ft_printf/src/pf_putptr.c \
                          libft/ft_printf/src/pf_putstr.c \
                          libft/ft_printf/src/pf_toupper.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_split.c \
                          libft/ft_strchr.c \
                          libft/ft_strdup.c \
                          libft/ft_striteri.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_strmapi.c \
                          libft/ft_strcmp.c\
                          libft/ft_strncmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_strrchr.c \
                          libft/ft_strtrim.c \
                          libft/ft_substr.c \
                          libft/ft_tolower.c \
                          libft/ft_toupper.c \
                          libft/get_next_line.c \
                          libft/get_next_line_utils.c \
                          src/main.c \
                          src/read_file.c \
                          src/draw.c \
                          src/read_file_utils.c \
                          src/draw_utils.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm


all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1

fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 

re:			fclean all

.PHONY:		all clean fclean re


