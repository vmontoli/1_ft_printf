/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy-strlcat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:44:28 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 18:19:12 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_orig_len;
	size_t	src_orig_len;
	size_t	dst_def_len;

	dst_orig_len = ft_strlen(dst);
	if (dstsize > 0 && dstsize >= dst_orig_len)
		src_orig_len = ft_strlcpy(
				&(dst[dst_orig_len]), src, (dstsize - dst_orig_len));
	else
		src_orig_len = ft_strlen(src);
	dst_def_len = ft_size_t_min(dstsize, dst_orig_len);
	return (dst_def_len + src_orig_len);
}
