/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 07:53:42 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 19:03:33 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos0_in_hs;
	size_t	pos_in_ndl_n_delta_in_hs;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	len = ft_size_t_min(len, ft_strlen(haystack));
	if (len == 0 || len < ft_strlen(needle))
		return (NULL);
	pos0_in_hs = 0;
	pos_in_ndl_n_delta_in_hs = 0;
	while (pos0_in_hs <= (len - ft_strlen(needle)))
	{
		if (needle[pos_in_ndl_n_delta_in_hs] == '\0')
			return ((char *)&haystack[pos0_in_hs]);
		if (haystack[pos0_in_hs + pos_in_ndl_n_delta_in_hs]
			!= needle[pos_in_ndl_n_delta_in_hs])
		{
			pos0_in_hs++;
			pos_in_ndl_n_delta_in_hs = 0;
		}
		else
			pos_in_ndl_n_delta_in_hs++;
	}
	return (NULL);
}
