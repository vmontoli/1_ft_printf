/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper-tolower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:53:40 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/16 03:18:48 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 0x20);
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 0x20);
	return (c);
}
