/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:15 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 10:57:36 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>

# include "status.h"
# include "types.h"

int			ft_atoi(const t_string str);
long		ft_atol(const t_string str);
double		ft_strtod(const t_string str, t_string *endptr);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa(int n);
char		**ft_split(const char *s, const char *set);
char		*ft_strdup(const char *s);
char		*ft_strjoin_sep(const char *s1, char sep, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

size_t		ft_intlen(int n);
size_t		ft_strlen(const char *s);

void		ft_free_str(char **str);
void		ft_free_tab(char ***tab);

t_status	ft_isalnum(int c);
t_status	ft_isalpha(int c);
t_status	ft_isascii(int c);
t_status	ft_isdigit(int c);
t_status	ft_isprint(int c);
t_status	ft_isspace(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

#endif
