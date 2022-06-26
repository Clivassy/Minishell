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
YANNCOMPILE += src/10_initialisation/data_initialisation.c
YANNCOMPILE += src/25_expand/expand.c
YANNCOMPILE += src/27_rm_quotes/rm_quotes_in_token.c
YANNCOMPILE += src/27_rm_quotes/rm_quotes_in_token_list.c
YANNCOMPILE += src/28_exec_list_creation/count_pipes.c
YANNCOMPILE += src/28_exec_list_creation/create_exec_elm_list.c
YANNCOMPILE += src/36_command_execution/exec_command.c
YANNCOMPILE += src/40_builtin/echo.c
YANNCOMPILE += src/40_builtin/cd.c
YANNCOMPILE += src/45_environment/env_initialisation.c
YANNCOMPILE += src/45_environment/env_manipulation.c
YANNCOMPILE += src/50_exit_functions/exit.c
YANNCOMPILE += src/60_tools/create_token_list.c
YANNCOMPILE += src/60_tools/exec_elm_manipulation.c
YANNCOMPILE += src/60_tools/ft_add_to_str.c
YANNCOMPILE += src/60_tools/ft_rm_from_str.c
YANNCOMPILE += src/60_tools/garbage_collector_1.c
YANNCOMPILE += src/60_tools/garbage_collector_2.c
YANNCOMPILE += src/60_tools/print_color.c
YANNCOMPILE += src/60_tools/tkn_manipulation.c
YANNCOMPILE += src/70_debug/print_env.c
YANNCOMPILE += src/70_debug/print_exec_elm_list.c
YANNCOMPILE += src/70_debug/test_add_to_str.c
YANNCOMPILE += src/70_debug/test_echo.c
YANNCOMPILE += src/70_debug/test_exec_list_creation.c
YANNCOMPILE += src/70_debug/test_garbage_collector.c
YANNCOMPILE += src/70_debug/test_env.c
YANNCOMPILE += src/70_debug/test_expand.c
YANNCOMPILE += src/70_debug/test_rm_from_str.c
YANNCOMPILE += src/70_debug/test_rm_quotes.c

JULIACOMPILE = main_julia.c
JULIACOMPILE += src/10_initialisation/data_initialisation.c
JULIACOMPILE += src/20_parser_lexer/lexer.c
JULIACOMPILE += src/20_parser_lexer/parser.c
JULIACOMPILE += src/20_parser_lexer/lexer_errors.c
JULIACOMPILE += src/20_parser_lexer/lexer_utils.c
JULIACOMPILE += src/20_parser_lexer/lexer_metacharacters.c
JULIACOMPILE += src/20_parser_lexer/lexer_words.c
JULIACOMPILE += src/20_parser_lexer/heredoc.c
JULIACOMPILE += src/60_tools/garbage_collector_1.c
JULIACOMPILE += src/60_tools/garbage_collector_2.c
JULIACOMPILE += src/60_tools/print_color.c
JULIACOMPILE += src/50_exit_functions/exit.c
JULIACOMPILE += src/60_tools/tkn_manipulation.c


yann: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${YANNCOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

julia: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${JULIACOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}
