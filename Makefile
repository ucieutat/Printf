# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 21:49:41 by ucieutat          #+#    #+#              #
#    Updated: 2021/11/26 11:08:27 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c tools.c

OBJS = ${SRCS:.c=.o}

HEADERS = printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = libftprintf.a

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}
	

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}


re:	fclean all

.PHONY: all clean fclean re
