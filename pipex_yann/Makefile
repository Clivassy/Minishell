# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 18:59:09 by ybellot           #+#    #+#              #
#    Updated: 2022/03/18 20:27:55 by ybellot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########   BASE   ##########
# File name
NAME = pipex

# Sources
SRCS += sources/exec_command.c
SRCS += sources/error.c
SRCS += sources/free_pointer_array.c
SRCS += sources/split.c
SRCS += sources/strjoin.c
SRCS += sources/strlen.c
SRCS += sources/strnstr.c
SRCS += sources/main.c

OBJS = ${SRCS:.c=.o}

HEADER = includes/pipex.h

INCLUDES_DIR= -I ./includes

# Compilateurs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

##########   Cst mise en forme   ##########
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

##########   RULES   ##########

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ echo "${_CYAN}start $@${_END}"
	${CC} ${SRCS} -o ${NAME} ${CFLAGS} ${INCLUDES_DIR}
	@ echo "${_GREEN}$(NAME) compiled${_END}"

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES_DIR)

clean:
	@ echo "${_CYAN}start $@${_END}"
	rm -f $(OBJS)
	@ echo "${_GREEN}$@ done${_END}"

fclean: clean
	@ echo "${_CYAN}start $@${_END}"
	rm -f $(NAME)
	@ echo "${_GREEN}$@ done${_END}"

re: fclean all
	@ echo "${_CYAN}start $@${_END}"
	@ echo "${_GREEN}$@ done${_END}"

.PHONY: all clean fclean re

.SILENT:

