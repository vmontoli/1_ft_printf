/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:55:24 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/09 15:04:48 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n_bytes;
	void	*ptr;

	n_bytes = count * size;
	ptr = malloc(n_bytes);
	if (ptr != NULL)
		ft_memset(ptr, 0, n_bytes);
	return (ptr);
}
