NAME = pipex

SRCS = pipex.c ft_utils.c ft_split.c ft_parsing.c ft_strjoin.c ft_errors.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME} pipex.h
${NAME}: ${OBJS}
	@${MAKE} -C ./ft_printf
	@${CC} ${CFLAGS} ${OBJS} ./ft_printf/ft_printf -o pipex

clean:
	@${MAKE} -C ./ft_printf fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
