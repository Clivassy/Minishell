##########   BASE   ##########
# File name
NAME = minishell

# Sources
SRCS += src/main.c

OBJS = ${SRCS:.c=.o}

HEADER += includes/minishell.h
HEADER += libft/libft.h

INCLUDES_DIR= -I ./includes/ -I ./libft/

LIB_INCLUDE = -L ./libft -lft

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



TOCOMPILE = main_yann.c
TOCOMPILE += src/10_initialisation/start_initialisation.c
TOCOMPILE += src/30_command_execution/exec_command.c
TOCOMPILE += src/40_builtin/echo.c
TOCOMPILE += src/50_exit_functions/exit.c
TOCOMPILE += src/60_tools/lst_manipulation.c
TOCOMPILE += src/60_tools/elm_manipulation.c
TOCOMPILE += src/70_debug/test_echo.c
TOCOMPILE += src/70_debug/print_env.c



yann: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${TOCOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

julia: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} src/*.c main_julia.c -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}
