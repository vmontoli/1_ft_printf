/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy-memmove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:39:41 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 03:49:11 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	return (ft_memmove(dst, src, n));
}

static void	*ft_memmove_left(void *dst, const void *src, size_t len)
{
	char		*dst_char;
	const char	*src_char;
	size_t		i;

	dst_char = (char *) dst;
	src_char = (const char *) src;
	i = 0;
	while (i < len)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}

static void	*ft_memmove_right(void *dst, const void *src, size_t len)
{
	char		*dst_char;
	const char	*src_char;
	size_t		i;

	dst_char = (char *) dst;
	src_char = (const char *) src;
	i = len;
	while (i > 0)
	{
		i--;
		dst_char[i] = src_char[i];
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0 || (dst == src))
		return (dst);
	if (dst < src)
		return (ft_memmove_left(dst, src, len));
	else
		return (ft_memmove_right(dst, src, len));
}
