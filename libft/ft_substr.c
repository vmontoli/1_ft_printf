/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 06:43:42 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 18:19:38 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	dstsize;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	dstsize = ft_size_t_min(s_len - start, len) + 1;
	result = (char *) ft_calloc(dstsize, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s + start, dstsize);
	return (result);
}
