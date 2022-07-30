/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:39:33 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/20 16:35:15 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// libft
int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
size_t	ft_strlen(char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	*ft_memmove(void *destination, const void *source, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int character);
int		ft_tolower(int character);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strrchr(const char *string, int searchedChar);
int		ft_strncmp(const char *first, const char *second, size_t length);
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *pointer1, const void *pointer2, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *theString);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_splitlen(char **split);
void	ft_free_split(char **split_result);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//gnl
char	*get_next_line(int fd);
char	*ft_gnl_algo(int fd, char (*buf)[BUFFER_SIZE], char **line);
int		ft_cpy_bufftoline(char **line, char *buff);
int		ft_cpy_line_and_buff(char *dst, char *src, char *buff);
void	ft_translat_buffer(char *buf, int nb);
size_t	ft_buflen(char *str);
char	*ft_initbuffer(char *buf);
int		ft_has_eol(char *str);

//FT_PRINTF
int		ft_printf(const char *s, ...);
void	ft_putchar(int c, int *count);
void	ft_search_format(va_list args, int *count, const char s);
void	ft_is_hexa(unsigned int nb, const char c, int *count);
void	ft_is_i_or_d(int nb, int *count);
void	ft_is_pointer(unsigned long long ptr, int *count);
void	ft_print_str(char *str, int *count);
void	ft_print_unsigned(unsigned int n, int *count);
char	*ft_utoa(unsigned int nb);
char	*ft_strncpy(char *dest, char *src, int n);
#endif
