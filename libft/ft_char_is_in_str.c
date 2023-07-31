/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_is_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:28:12 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 18:28:53 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_char_is_in_str(char c, const char *s)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (true);
		s++;
	}
	return (false);
}
