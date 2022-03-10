# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 10:30:09 by lvan-tic          #+#    #+#              #
#    Updated: 2022/03/10 10:30:10 by lvan-tic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

READLINE_LIB = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/ -I/Users/$(USER)/.brew/opt/readline/include

SRCS = ms.c utils.c builtins.c utils_func.c

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

INCLUDES = -I.

OBJS	= ${SRCS:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${READLINE_LIB} -o $(NAME)

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
