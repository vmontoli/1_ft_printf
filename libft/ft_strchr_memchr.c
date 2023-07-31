/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr-memchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 07:05:17 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 04:10:37 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*current;
	char	tofind;

	current = (char *) s;
	tofind = (char) c;
	while (*current != '\0')
	{
		if (*current == tofind)
			return (current);
		current++;
	}
	if (tofind == '\0')
		return (current);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*current;
	char	tofind;

	current = (char *) s + ft_strlen(s);
	tofind = (char) c;
	if (tofind == '\0')
		return (current);
	while (current >= s)
	{
		if (*current == tofind)
			return (current);
		current--;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*current;
	char	tofind;
	size_t	i;

	current = (void *) s;
	tofind = (char) c;
	i = 0;
	while (i < n)
	{
		if (current[i] == tofind)
			return (&current[i]);
		i++;
	}
	return (NULL);
}
