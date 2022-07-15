##########   BASE   ##########
# File name
NAME = minishell

# Sources

SRCS += main.c
SRCS += src/10_initialisation/data_initialisation.c
SRCS += src/15_minishell_loop/minishell_loop.c
SRCS += src/17_error_management/error_cd.c
SRCS += src/17_error_management/error_close.c
SRCS += src/17_error_management/error_cmd_not_found.c
SRCS += src/17_error_management/error_dup2.c
SRCS += src/17_error_management/error_execve.c
SRCS += src/17_error_management/error_exit.c
SRCS += src/17_error_management/error_fork.c
SRCS += src/17_error_management/error_pipe.c
SRCS += src/17_error_management/error_pwd.c
SRCS += src/17_error_management/print_error_open.c
SRCS += src/17_error_management/print_error.c
SRCS += src/20_lexer/lexer.c
SRCS += src/20_lexer/lexer_utils.c
SRCS += src/20_lexer/lexer_metacharacters.c
SRCS += src/20_lexer/lexer_words.c
SRCS += src/21_parser/parser.c
SRCS += src/21_parser/parser_utils.c
SRCS += src/22_heredoc/heredoc.c
SRCS += src/22_heredoc/heredoc_utils.c
SRCS += src/22_heredoc/heredoc_manipulation.c
SRCS += src/22_heredoc/test_heredoc.c
SRCS += src/23_gp_tkn_lst/gp_tokens.c
SRCS += src/23_gp_tkn_lst/gp_tokens_utils.c
SRCS += src/24_signals/signals_1.c
SRCS += src/24_signals/signals_2.c
SRCS += src/24_signals/signals_3.c
SRCS += src/25_expand/expand_1.c
SRCS += src/25_expand/expand_2.c
SRCS += src/27_rm_quotes/rm_quotes_in_token.c
SRCS += src/27_rm_quotes/rm_quotes_in_token_list.c
SRCS += src/28_exec_list_creation/count_pipes.c
SRCS += src/28_exec_list_creation/create_exec_elm_list.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_gp_token_list.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_redirection_token.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_token_cmd.c
SRCS += src/30_read_gp_token_to_fill_exec_list/read_token_heredoc.c
SRCS += src/36_command_execution/close_fd.c
SRCS += src/36_command_execution/exec_all_commands.c
SRCS += src/36_command_execution/exec_one_command.c
SRCS += src/36_command_execution/find_command_path.c
SRCS += src/36_command_execution/manage_fd_and_redirections.c
SRCS += src/40_builtin/builtin_cd.c
SRCS += src/40_builtin/builtin_echo.c
SRCS += src/40_builtin/builtin_env.c
SRCS += src/40_builtin/builtin_exit.c
SRCS += src/40_builtin/builtin_export.c
SRCS += src/40_builtin/builtin_pwd.c
SRCS += src/40_builtin/builtin_unset.c
SRCS += src/40_builtin/ft_is_builtin.c
SRCS += src/45_environment/env_initialisation.c
SRCS += src/45_environment/env_manipulation_1.c
SRCS += src/45_environment/env_manipulation_2.c
SRCS += src/50_exit_functions/exit.c
SRCS += src/60_tools/exec_elm_manipulation.c
SRCS += src/60_tools/ft_add_to_str.c
SRCS += src/60_tools/ft_null_terminated_tab_len.c
SRCS += src/60_tools/ft_rm_from_str.c
SRCS += src/60_tools/ft_split_with_garbage_collector.c
SRCS += src/60_tools/ft_strcmp.c
SRCS += src/60_tools/garbage_collector_1.c
SRCS += src/60_tools/garbage_collector_2.c
SRCS += src/60_tools/print_color.c
SRCS += src/60_tools/tkn_manipulation.c

OBJS = ${SRCS:.c=.o}

HEADER += includes/error_message.h
HEADER += includes/minishell.h
HEADER += libft/libft.h

INCLUDES_DIR= -I ./includes/ -I ./libft/

LIB_INCLUDE = -L ./libft -lft

# Compilateurs
CC = cc
#CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g

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
YANNCOMPILE += src/17_error_management/error_cd.c
YANNCOMPILE += src/17_error_management/error_close.c
YANNCOMPILE += src/17_error_management/error_cmd_not_found.c
YANNCOMPILE += src/17_error_management/error_dup2.c
YANNCOMPILE += src/17_error_management/error_execve.c
YANNCOMPILE += src/17_error_management/error_exit.c
YANNCOMPILE += src/17_error_management/error_fork.c
YANNCOMPILE += src/17_error_management/error_pipe.c
YANNCOMPILE += src/17_error_management/error_pwd.c
YANNCOMPILE += src/17_error_management/print_error_open.c
YANNCOMPILE += src/17_error_management/print_error.c
YANNCOMPILE += src/22_heredoc/heredoc_manipulation.c
YANNCOMPILE += src/24_signals/signals_exec.c
YANNCOMPILE += src/24_signals/signals_prompt.c
YANNCOMPILE += src/24_signals/signals_heredoc.c
YANNCOMPILE += src/25_expand/expand_1.c
YANNCOMPILE += src/25_expand/expand_2.c
YANNCOMPILE += src/27_rm_quotes/rm_quotes_in_token.c
YANNCOMPILE += src/27_rm_quotes/rm_quotes_in_token_list.c
YANNCOMPILE += src/28_exec_list_creation/count_pipes.c
YANNCOMPILE += src/28_exec_list_creation/create_exec_elm_list.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_gp_token_list.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_redirection_token.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_token_cmd.c
YANNCOMPILE += src/30_read_gp_token_to_fill_exec_list/read_token_heredoc.c
YANNCOMPILE += src/36_command_execution/close_fd.c
YANNCOMPILE += src/36_command_execution/exec_all_commands.c
YANNCOMPILE += src/36_command_execution/exec_one_command.c
YANNCOMPILE += src/36_command_execution/find_command_path.c
YANNCOMPILE += src/36_command_execution/manage_fd_and_redirections.c
YANNCOMPILE += src/40_builtin/ft_is_builtin.c
YANNCOMPILE += src/45_environment/env_initialisation.c
YANNCOMPILE += src/45_environment/env_manipulation_1.c
YANNCOMPILE += src/45_environment/env_manipulation_2.c
YANNCOMPILE += src/50_exit_functions/exit.c
YANNCOMPILE += src/60_tools/exec_elm_manipulation.c
YANNCOMPILE += src/60_tools/ft_add_to_str.c
YANNCOMPILE += src/60_tools/ft_null_terminated_tab_len.c
YANNCOMPILE += src/60_tools/ft_rm_from_str.c
YANNCOMPILE += src/60_tools/ft_split_with_garbage_collector.c
YANNCOMPILE += src/60_tools/ft_strcmp.c
YANNCOMPILE += src/60_tools/garbage_collector_1.c
YANNCOMPILE += src/60_tools/garbage_collector_2.c
YANNCOMPILE += src/60_tools/print_color.c
YANNCOMPILE += src/60_tools/tkn_manipulation.c
YANNCOMPILE += src/70_debug/create_exec_list.c
YANNCOMPILE += src/70_debug/create_token_list.c
YANNCOMPILE += src/70_debug/print_env.c
YANNCOMPILE += src/70_debug/print_exec_elm_list.c
YANNCOMPILE += src/70_debug/print_token_list.c
YANNCOMPILE += src/70_debug/print_fd_status.c
YANNCOMPILE += src/70_debug/test_add_to_str.c
YANNCOMPILE += src/70_debug/test_builtin_cd_pwd.c
YANNCOMPILE += src/70_debug/test_builtin_echo.c
YANNCOMPILE += src/70_debug/test_command_execution.c
YANNCOMPILE += src/70_debug/test_env.c
YANNCOMPILE += src/70_debug/test_exec_list_creation.c
YANNCOMPILE += src/70_debug/test_expand.c
YANNCOMPILE += src/70_debug/test_ft_split_garbage_collector.c
YANNCOMPILE += src/70_debug/test_garbage_collector.c
YANNCOMPILE += src/70_debug/test_read_gp_token_to_fill_exec_list.c
YANNCOMPILE += src/70_debug/test_rm_from_str.c
YANNCOMPILE += src/70_debug/test_rm_quotes.c

JULIACOMPILE += main_julia.c
JULIACOMPILE += src/10_initialisation/data_initialisation.c
JULIACOMPILE += src/15_minishell_loop/minishell_loop.c
JULIACOMPILE += src/17_error_management/error_close.c
JULIACOMPILE += src/17_error_management/error_cmd_not_found.c
JULIACOMPILE += src/17_error_management/error_dup2.c
JULIACOMPILE += src/17_error_management/error_execve.c
JULIACOMPILE += src/17_error_management/error_exit.c
JULIACOMPILE += src/17_error_management/error_fork.c
JULIACOMPILE += src/17_error_management/error_pipe.c
JULIACOMPILE += src/17_error_management/error_pwd.c
JULIACOMPILE += src/17_error_management/print_error_open.c
JULIACOMPILE += src/17_error_management/print_error.c
JULIACOMPILE += src/17_error_management/error_cd.c
JULIACOMPILE += src/20_lexer/lexer.c
JULIACOMPILE += src/20_lexer/lexer_utils.c
JULIACOMPILE += src/20_lexer/lexer_metacharacters.c
JULIACOMPILE += src/20_lexer/lexer_words.c
JULIACOMPILE += src/21_parser/parser.c
JULIACOMPILE += src/21_parser/parser_utils.c
JULIACOMPILE += src/22_heredoc/heredoc.c
JULIACOMPILE += src/22_heredoc/heredoc_utils.c
JULIACOMPILE += src/22_heredoc/heredoc_manipulation.c
JULIACOMPILE += src/22_heredoc/test_heredoc.c
JULIACOMPILE += src/23_gp_tkn_lst/gp_tokens.c
JULIACOMPILE += src/23_gp_tkn_lst/gp_tokens_utils.c
JULIACOMPILE += src/24_signals/signals_exec.c
JULIACOMPILE += src/24_signals/signals_prompt.c
JULIACOMPILE += src/24_signals/signals_heredoc.c
JULIACOMPILE += src/25_expand/expand_1.c
JULIACOMPILE += src/25_expand/expand_2.c
JULIACOMPILE += src/27_rm_quotes/rm_quotes_in_token.c
JULIACOMPILE += src/27_rm_quotes/rm_quotes_in_token_list.c
JULIACOMPILE += src/28_exec_list_creation/count_pipes.c
JULIACOMPILE += src/28_exec_list_creation/create_exec_elm_list.c
JULIACOMPILE += src/30_read_gp_token_to_fill_exec_list/read_gp_token_list.c
JULIACOMPILE += src/30_read_gp_token_to_fill_exec_list/read_redirection_token.c
JULIACOMPILE += src/30_read_gp_token_to_fill_exec_list/read_token_cmd.c
JULIACOMPILE += src/30_read_gp_token_to_fill_exec_list/read_token_heredoc.c
JULIACOMPILE += src/36_command_execution/close_fd.c
JULIACOMPILE += src/36_command_execution/exec_all_commands.c
JULIACOMPILE += src/36_command_execution/exec_one_command.c
JULIACOMPILE += src/36_command_execution/find_command_path.c
JULIACOMPILE += src/36_command_execution/manage_fd_and_redirections.c
JULIACOMPILE += src/40_builtin/builtin_echo.c
JULIACOMPILE += src/40_builtin/builtin_env.c
JULIACOMPILE += src/40_builtin/builtin_cd.c
JULIACOMPILE += src/40_builtin/builtin_exit.c
JULIACOMPILE += src/40_builtin/builtin_pwd.c
JULIACOMPILE += src/40_builtin/ft_is_builtin.c
JULIACOMPILE += src/40_builtin/builtin_unset.c
JULIACOMPILE += src/40_builtin/builtin_export.c
JULIACOMPILE += src/45_environment/env_initialisation.c
JULIACOMPILE += src/45_environment/env_manipulation_1.c
JULIACOMPILE += src/45_environment/env_manipulation_2.c
JULIACOMPILE += src/50_exit_functions/exit.c
JULIACOMPILE += src/60_tools/exec_elm_manipulation.c
JULIACOMPILE += src/60_tools/ft_add_to_str.c
JULIACOMPILE += src/60_tools/ft_rm_from_str.c
JULIACOMPILE += src/60_tools/garbage_collector_1.c
JULIACOMPILE += src/60_tools/garbage_collector_2.c
JULIACOMPILE += src/60_tools/print_color.c
JULIACOMPILE += src/60_tools/tkn_manipulation.c
JULIACOMPILE += src/60_tools/ft_split_with_garbage_collector.c
JULIACOMPILE += src/60_tools/ft_strcmp.c
JULIACOMPILE += src/60_tools/ft_null_terminated_tab_len.c
JULIACOMPILE += src/70_debug/create_exec_list.c
JULIACOMPILE += src/70_debug/create_token_list.c
JULIACOMPILE += src/70_debug/print_env.c
JULIACOMPILE += src/70_debug/print_exec_elm_list.c
JULIACOMPILE += src/70_debug/print_token_list.c
JULIACOMPILE += src/70_debug/print_fd_status.c
JULIACOMPILE += src/70_debug/test_command_execution.c
JULIACOMPILE += src/70_debug/test_add_to_str.c
JULIACOMPILE += src/70_debug/test_builtin_echo.c
JULIACOMPILE += src/70_debug/test_builtin_cd_pwd.c
JULIACOMPILE += src/70_debug/test_env.c
JULIACOMPILE += src/70_debug/test_exec_list_creation.c
JULIACOMPILE += src/70_debug/test_expand.c
JULIACOMPILE += src/70_debug/test_garbage_collector.c
JULIACOMPILE += src/70_debug/test_read_gp_token_to_fill_exec_list.c
JULIACOMPILE += src/70_debug/test_rm_from_str.c
JULIACOMPILE += src/70_debug/test_rm_quotes.c

yann: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${YANNCOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

julia: $(HEADER)
	rm -f $(NAME)
	make -C ./libft all
	${CC} ${JULIACOMPILE} -l readline -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}
