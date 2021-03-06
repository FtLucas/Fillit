/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:16:52 by dacuvill          #+#    #+#             */
/*   Updated: 2018/12/17 16:05:44 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BUFF_SIZE 20

typedef	struct		s_lst
{
	int				file_d;
	char			*content;
	struct s_lst	*next;
}					t_lst;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *str);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				**ft_strsplit(const char *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
size_t				ft_strchri(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *hay, const char *nee);
char				*ft_strnstr(const char *hay, const char *nee, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_swap(int *a, int *b);
int					ft_atoi_base(const char *str, int base);
char				*ft_itoa(int n);
int					ft_power(int n, int p);
int					ft_sqrt(int nb);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
t_list				*ft_lstnew(const void *content, size_t content_size);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strfreejoin(const char *s1, const char *s2, int c);
int					get_next_line(const int fd, char **line);

#endif
