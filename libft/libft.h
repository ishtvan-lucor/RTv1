/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:27:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/09 16:56:23 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_tail
{
	int				fd;
	char			tail[BUFF_SIZE];
}					t_tail;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

void				ft_bzero(void *s, size_t n);
void				ft_free_after_split(char **str, size_t len);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstswap(t_list *lst1, t_list *lst2);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_set_vector(t_vector *v, double x, double y, double z);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *src, size_t old_size, size_t new_size);
char				*ft_itoa(int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
int					ft_isdouble_or_int(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_iscolor_rgb(const char *s);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char*s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);
size_t				ft_intlen(int n);
size_t				ft_strclen(char const *s, size_t start, char const c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
size_t				ft_wordssplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
double				ft_string_to_double(const char *str);
double				v_dot_prd(const t_vector *v1, const t_vector *v2);
double				v_len(const t_vector *vec);
t_vector			v_nrm(const t_vector *v);
t_vector			v_plus(const t_vector *v1, const t_vector *v2);
t_vector			v_minus(const t_vector *v1, const t_vector *v2);
t_vector			v_mult(const t_vector *v1, const t_vector *v2);
t_vector			v_div(const t_vector *v1, const t_vector *v2);
t_vector			v_plus_n(const t_vector *vec, double nbr);
t_vector			v_minus_n(const t_vector *vec, double nbr);
t_vector			v_mult_n(const t_vector *vec, double nbr);
t_vector			v_div_n(const t_vector *vec, double nbr);

#endif
