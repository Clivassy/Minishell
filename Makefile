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

YANNCOMPILE = main_yann.c
YANNCOMPILE += src/10_initialisation/start_initialisation.c
YANNCOMPILE += src/30_command_execution/exec_command.c
YANNCOMPILE += src/40_builtin/echo.c
YANNCOMPILE += src/40_builtin/cd.c
YANNCOMPILE += src/50_exit_functions/exit.c
YANNCOMPILE += src/60_tools/elm_manipulation.c
YANNCOMPILE += src/60_tools/env_manipulation.c
YANNCOMPILE += src/60_tools/lst_manipulation.c
YANNCOMPILE += src/60_tools/garbage_collector_1.c
YANNCOMPILE += src/60_tools/garbage_collector_2.c
YANNCOMPILE += src/60_tools/print_color.c
YANNCOMPILE += src/70_debug/test_echo.c
YANNCOMPILE += src/70_debug/print_env.c
YANNCOMPILE += src/70_debug/test_garbage_collector.c

JULIACOMPILE = main_julia.c
JULIACOMPILE += src/20_parser_lexer/lexer.c
JULIACOMPILE += src/20_parser_lexer/parser.c
JULIACOMPILE += src/20_parser_lexer/lexer_errors.c
JULIACOMPILE += src/20_parser_lexer/manip_tokens.c

yann: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${YANNCOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

julia: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${JULIACOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}
