/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:47:43 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/19 13:10:42 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef HEXA
#  define HEXA "0123456789abcdef"
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Fonctions Maths
*/

int					ft_abs(int nb);
int					ft_sqrt(int nb);
int					ft_pow(int nb, int power);
int					ft_rec_fac(int nb);
int					ft_pyth(int ligne, int colonne);

/*
** Memory
*/

void				ft_memdel(void **ap);
void				ft_bzero(void *str, size_t len);
void				*ft_memset(void *str, int c, size_t len);
void				*ft_memchr(const void *buffer, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

/*
** Linked List
*/

void				ft_lstrev(t_list **liste);
void				ft_lstprint(t_list **list);
void				ft_lstclear(t_list **liste);
size_t				ft_lstsize(t_list *begin_list);
void				ft_lstadd(t_list **alst, t_list *new, int index);
void				ft_lstaddback(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));

/*
** Malloc
*/

void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
char				*ft_strdup(const char *src);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));

/*
** Strings
*/

void				ft_strclr(char *s);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *str, int n);
char				*ft_strrchr(const char *str, int n);
char				**ft_strsplit(char const *s, char c);
void				ft_striter(char *s, void (*f) (char *));
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strstr(const char *str, const char *to_find);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strnstr(const char *str, const char *to_find, size_t n);

/*
** Usuals
*/

int					ft_islower(int c);
int					ft_isalpha(int n);
int					ft_isdigit(int n);
int					ft_isalnum(int n);
int					ft_isascii(int n);
int					ft_isprint(int n);
int					ft_toupper(int n);
int					ft_tolower(int n);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
int					ft_isupper(int nb);
char				*ft_strrev(char *str);
void				ft_putendl(char const *s);
size_t				ft_strlen(const char *str);
void				ft_putstr(char const *str);
void				ft_putnbr_fd(int n, int fd);
int					ft_match(char *s1, char *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_base(int nb, int base);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putwchar(wchar_t str);
int					ft_putnwstr(const wchar_t *str, int len);
int					ft_wstrlen(wchar_t *str);
int					ft_calc_wstrlen(wchar_t *str, int precision, int i);

/*
** Other
*/

void				ft_swap(void **a, void **b);
char				*ft_itoa(ssize_t n);
int					ft_atoi(const char *str);
char				*ft_itoa_base_signed(ssize_t nb, int base);
char				*ft_itoa_base_uns(uintmax_t nbr, int base);
int					get_next_line(const int fd, char **line);

#endif
