/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:21:57 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/31 10:26:35 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Definition of size_t (and NULL):
 * There are only variables and macros (not forbidden),
 *  no external functions (forbidden) */
# include <stddef.h>

//Definition of bool (instead of _Bool), true, false)
# include <stdbool.h>

/*
//Definition of standard fd's; they are defined on <stdio.h> but has a lot of 
// function definitions
# define stdin  0
# define stdout 1
# define stderr 2
AAARRRGG norminette doesn't like this because lowercased (as on the stdio.h)
*/

/* PART 1 */

/*ft_isascii_more.c*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/*ft_toupper_tolower.c*/
int		ft_toupper(int c);
int		ft_tolower(int c);

/*ft_isupper_islower.c*/
// added for convenience, used for ft_isascii() & ft_toupper/lower()
int		ft_isupper(int c);
int		ft_islower(int c);

/*ft_strlen.c*/
size_t	ft_strlen(const char *s);

/*ft_memset_bzero.c*/
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*ft_memcpy_memmove.c*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

/*ft_strlcpy_stlcat.c*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*ft_size_t_max_min.c*/
//helper function for ft_strlcat
size_t	ft_size_t_max(size_t a, size_t b);
size_t	ft_size_t_min(size_t a, size_t b);

/*ft_strchr_memchr.c*/
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);

/*ft_strncmp_memcmp.c*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*ft_strnstr.c*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*ft_atoi.c*/
int		ft_atoi(const char *str);

/*ft_calloc.c*/
void	*ft_calloc(size_t count, size_t size);
			/*with malloc() [#include <stdlib.h> on its file]*/

/*ft_strdup.c*/
char	*ft_strdup(const char *s1);
			/*with malloc() [#include <stdlib.h> on its file]*/

/* PART 2 */

/*ft_substr.c*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
			/*with malloc() [#include <stdlib.h> on its file]*/
			/*ft_calloc() used instead*/

/*ft_strjoin.c*/
char	*ft_strjoin(char const *s1, char const *s2);
			/*with malloc() [#include <stdlib.h> on its file]*/

/*ft_strtrim.c*/
char	*ft_strtrim(char const *s1, char const *set);
			/*with malloc() [#include <stdlib.h> on its file]*/

/*ft_char_is_in_str.c*/
// useful for ft_strtrim()
bool	ft_char_is_in_str(char c, const char *s);

/*ft_split.c*/
char	**ft_split(char const *s, char c);
			/*with malloc() & free() [#include <stdlib.h> on its file]*/

/*ft_itoa.c*/
char	*ft_itoa(int n);
			/*with malloc() [#include <stdlib.h> on its file]*/
char	*ft_uitoa(unsigned int n);
			/*with malloc() [#include <stdlib.h> on its file]*/
			//useful for ft_printf project

/*ft_striteri_strmapi.c*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
			/*with malloc() [#include <stdlib.h> on its file]*/

/*ft_putstr_more.c*/
void	ft_putchar_fd(char c, int fd);
			/*with write() [#include <unistd.h> on its file]*/
void	ft_putstr_fd(char *s, int fd);
			/*with write() [#include <unistd.h> on its file]*/
void	ft_putendl_fd(char *s, int fd);
			/*with write() [#include <unistd.h> on its file]*/
			/*ft_putchar_fd() used instead*/

/*ft_putnbr.c*/
void	ft_putnbr_fd(int n, int fd);
			/*with write() [#include <unistd.h> on its file]*/
			/*ft_putchar_fd() used instead*/

/* BONUS */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*ft_lstnew_bonus.c*/
t_list	*ft_lstnew(void *content);
			/*with malloc() [#include <stdlib.h> on its file]*/

/*ft_lstadd_front_bonus.c*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*ft_lstsize_last_back_bonus.c*/
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*t_lstdelone_clear_iter_bonus.c*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
			/*with free() [#include <stdlib.h> on its file]*/
void	ft_lstclear(t_list **lst, void (*del)(void *));
			/*with free() [#include <stdlib.h> on its file]*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*ft_lstmap.c*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
			/*with malloc() & free() [#include <stdlib.h> on its file]*/
			/*used ft_lstnew() & ft_lstclear() instead*/

#endif
