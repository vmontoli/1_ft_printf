/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_t_max_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 04:00:21 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 18:20:45 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_t_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_size_t_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
