##########   BASE   ##########
# File name
NAME = minishell

# Sources
SRCS += src/*.c

OBJS = ${SRCS:.c=.o}

HEADER += includes/minishell.h
HEADER += libft/libft.h

INCLUDES_DIR= -I ./includes -I ./libft/

LIB_INCLUDE = -L ./libft

# Compilateurs
CC = cc
CFLAGS = -g
#CFLAGS = -Wall -Wextra -Werror

##########   RULES   ##########
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft all
	${CC} ${OBJS} -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}


%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES_DIR)

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re