SRCS	= ft_printf.c ft_search_format.c ft_printf_utils.c ft_print_hexa.c ft_print_integer.c ft_print_ptr.c ft_print_string.c ft_print_unsigned.c

OBJS	= ${SRCS:.c=.o}

CC	= gcc

NAME	= ft_printf

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -f

%.o : 	%.c
	${CC} -o $@ -c $< ${CFLAGS}
	
all : ${NAME}

$(NAME) : ${OBJS} ft_printf.h
	@ar rcs ${NAME} ${OBJS}

clean :
	@${RM} ${OBJS} ${OBJS_B}

fclean : clean
	@${RM} ${NAME}

re : fclean all
