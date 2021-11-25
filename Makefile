# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 21:49:41 by ucieutat          #+#    #+#              #
#    Updated: 2021/11/25 01:21:35 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c tools.c

OBJS = ${SRCS:.c=.o}

HEADERS = printf.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = ft_printf

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}
	

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}


re:	fclean all

.PHONY: all clean fclean re
