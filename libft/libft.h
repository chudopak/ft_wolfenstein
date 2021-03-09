/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:02:47 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/13 15:03:21 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

void				*ft_memset(void *dest, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
unsigned long		ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(char *str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_calloc(size_t number, size_t size);
void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *dst, const void *src, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int num);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, char ch);
char				*ft_strrchr(const char *str, char ch);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_itoa(int n);
char				*ft_strnstr(const char *str_big,
					const char *str_sm, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_substr(const char *s, unsigned int start, size_t len);

typedef struct		s_lis{
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned int	i;
	unsigned int	j;
}					t_lis;

typedef struct		s_trim{
	unsigned int	sign;
	unsigned int	offset;
	unsigned int	i;
	unsigned int	j;
}					t_trim;

typedef struct		s_trim1{
	char			*beg;
	char			*end;
	int				i;
	unsigned int	len;
}					t_trim1;

char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(const char *s, char c);
int					ft_strcmp(const char ch1, const char ch2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
char				*ft_strcpy(char *dst, char *src, int size);
void				ft_putnbr_u(unsigned int n);
int					ft_nblen_u(unsigned int nb);
void				ft_puthex_long(unsigned long long nb);
void				ft_puthex(unsigned int nb, int registr);
char				*join_free(char *str, char *buff);
int					ft_nblen(int nb);
int					ft_atoi_dbl_ptr(char **str);

#endif
