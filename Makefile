# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <cieutatulin@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 21:49:41 by ucieutat          #+#    #+#              #
#    Updated: 2021/11/24 15:18:08 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c print_flags.c tools.c

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

cleanf: clean
	rm -rf ${NAME}


re:	cleanf all

.PHONY: all clean cleanf re
