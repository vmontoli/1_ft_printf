/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper-islower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 03:08:27 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/16 03:18:17 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FUNCTIONS ADDED FOR CONVENIENCE FOR OTHERS, NOT IN THE SUBJECT

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/*'à': 0xE0 'À': 0xC0
 *'ö': 0xF6 'Ö': 0xD6
 *'ø': 0xF8 'Ø': 0xD8
 *'þ': 0xFE 'Þ': 0xDE
 * */
