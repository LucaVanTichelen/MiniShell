NAME = minishell

READLINE_LIB = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/ -I/Users/$(USER)/.brew/opt/readline/include

SRCS = execve.c execute.c parser.c ms.c utils.c builtins.c utils_func.c env.c lst_utils.c

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
