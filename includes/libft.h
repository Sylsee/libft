/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:34:43 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/17 15:07:43 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <errno.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

/*			ALLOC			*/

typedef struct s_link
{
	struct s_link	*prev;
	struct s_link	*next;
}					t_link;

typedef struct s_area
{
	struct s_link	*freelist;
}					t_area;

extern t_area		g_ftarea;

t_area				*init_area(t_area *area);

/*			MEM				*/

void				*alloc(size_t size, t_area *area);
void				free_one(void *ptr, t_area *area);
void				free_area(t_area *area);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isnumeric(const char *s);

size_t				ft_strlen(const char *str);
size_t				ft_tablen(char **tab);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strict_strcmp(const char *s1, const char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
void				ft_strrev(char *str);
char				*ft_strextract(char const *s, char const *set);
int					ft_strend(char *s, char *set);
int					ft_charset(char c, const char *set);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strcontains(const char *s, const char *set);

int					ft_atoi(const char *nptr);
double				ft_atof(char *s);
char				*ft_itoa(int n);
int					ft_nbrlen(long nb);
char				*ft_itox(int nb);
int					ft_xtoi(const char *hexstring);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_str3join(const char *s1, const char *s2,
						const char *s3);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char *set);
void				ft_free_tab(char **tab, t_area *area);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(unsigned char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putxchar_fd(char c, int fd, int x);
void				ft_putbits_fd(size_t size, void *ptr, int fd);

/*			CHAINED LIST			*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
