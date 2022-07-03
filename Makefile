##########   BASE   ##########
# File name
NAME = minishell

# Sources


SRCS += main.c
SRCS += src/10_initialisation/data_initialisation.c
SRCS += src/15_minishell_loop/minishell_loop.c
SRCS += src/17_error_management/print_error.c
SRCS += src/20_lexer/lexer.c
SRCS += src/20_lexer/lexer_errors.c
SRCS += src/20_lexer/lexer_utils.c
SRCS += src/20_lexer/lexer_metacharacters.c
SRCS += src/20_lexer/lexer_words.c
SRCS += src/21_parser/parser.c
SRCS += src/22_gp_tkn_lst/gp_tokens.c
SRCS += src/22_gp_tkn_lst/gp_tokens_utils.c
SRCS += src/23_heredoc/heredoc.c
SRCS += src/23_heredoc/heredoc_utils.c
SRCS += src/23_heredoc/test_heredoc.c
SRCS += src/24_signals/signals.c
SRCS += src/25_expand/expand.c
SRCS += src/27_rm_quotes/rm_quotes_in_token.c
SRCS += src/27_rm_quotes/rm_quotes_in_token_list.c
SRCS += src/28_exec_list_creation/count_pipes.c
SRCS += src/28_exec_list_creation/create_exec_elm_list.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_gp_token_list.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_redirection_token.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_token_cmd.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_token_heredoc.c
SRCS += src/36_command_execution/exec_command.c
SRCS += src/36_command_execution/find_command_path.c
SRCS += src/40_builtin/echo.c
SRCS += src/40_builtin/cd.c
SRCS += src/45_environment/env_initialisation.c
SRCS += src/45_environment/env_manipulation.c
SRCS += src/50_exit_functions/exit.c
SRCS += src/60_tools/create_exec_list.c
SRCS += src/60_tools/create_token_list.c
SRCS += src/60_tools/exec_elm_manipulation.c
SRCS += src/60_tools/ft_add_to_str.c
SRCS += src/60_tools/ft_rm_from_str.c
SRCS += src/60_tools/garbage_collector_1.c
SRCS += src/60_tools/garbage_collector_2.c
SRCS += src/60_tools/print_color.c
SRCS += src/60_tools/tkn_manipulation.c
SRCS += src/70_debug/print_env.c
SRCS += src/70_debug/print_exec_elm_list.c
SRCS += src/70_debug/print_token_list.c
SRCS += src/70_debug/test_command_execution.c
SRCS += src/70_debug/test_add_to_str.c
SRCS += src/70_debug/test_echo.c
SRCS += src/70_debug/test_env.c
SRCS += src/70_debug/test_exec_list_creation.c
SRCS += src/70_debug/test_expand.c
SRCS += src/70_debug/test_garbage_collector.c
SRCS += src/70_debug/test_read_gp_token_to_fill_exec_list.c
SRCS += src/70_debug/test_rm_from_str.c
SRCS += src/70_debug/test_rm_quotes.c


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
	${CC} ${SRCS} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

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
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_gp_token_list.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_redirection_token.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_token_cmd.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_token_heredoc.c
YANNCOMPILE += src/36_command_execution/exec_command.c
YANNCOMPILE += src/36_command_execution/find_command_path.c
YANNCOMPILE += src/40_builtin/echo.c
YANNCOMPILE += src/40_builtin/cd.c
YANNCOMPILE += src/45_environment/env_initialisation.c
YANNCOMPILE += src/45_environment/env_manipulation.c
YANNCOMPILE += src/50_exit_functions/exit.c
YANNCOMPILE += src/60_tools/create_exec_list.c
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
YANNCOMPILE += src/70_debug/print_token_list.c
YANNCOMPILE += src/70_debug/test_command_execution.c
YANNCOMPILE += src/70_debug/test_add_to_str.c
YANNCOMPILE += src/70_debug/test_echo.c
YANNCOMPILE += src/70_debug/test_env.c
YANNCOMPILE += src/70_debug/test_exec_list_creation.c
YANNCOMPILE += src/70_debug/test_expand.c
YANNCOMPILE += src/70_debug/test_garbage_collector.c
YANNCOMPILE += src/70_debug/test_read_gp_token_to_fill_exec_list.c
YANNCOMPILE += src/70_debug/test_rm_from_str.c
YANNCOMPILE += src/70_debug/test_rm_quotes.c

JULIACOMPILE = main_julia.c
JULIACOMPILE += src/20_lexer/lexer.c
JULIACOMPILE += src/20_lexer/lexer_errors.c
JULIACOMPILE += src/20_lexer/lexer_utils.c
JULIACOMPILE += src/20_lexer/lexer_metacharacters.c
JULIACOMPILE += src/20_lexer/lexer_words.c
JULIACOMPILE += src/21_parser/parser.c
JULIACOMPILE += src/21_parser/parser_utils.c
JULIACOMPILE += src/22_gp_tkn_lst/gp_tokens.c
JULIACOMPILE += src/22_gp_tkn_lst/gp_tokens_utils.c
JULIACOMPILE += src/23_heredoc/heredoc.c
JULIACOMPILE += src/23_heredoc/heredoc_utils.c
JULIACOMPILE += src/23_heredoc/test_heredoc.c
JULIACOMPILE += src/24_signals/signals.c
JULIACOMPILE += src/50_exit_functions/exit.c
JULIACOMPILE += src/60_tools/tkn_manipulation.c
JULIACOMPILE += src/60_tools/garbage_collector_1.c
JULIACOMPILE += src/60_tools/garbage_collector_2.c
JULIACOMPILE += src/60_tools/print_color.c
JULIACOMPILE += src/70_debug/print_token_list.c

yann: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${YANNCOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

julia: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${JULIACOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}
