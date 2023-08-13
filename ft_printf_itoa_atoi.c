/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_atoi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:56:13 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/13 22:10:29 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const static char	*g_hex_chars_u = "0123456789ABCDEF";
const static char	*g_hex_chars_l = "0123456789abcdef";

unsigned int	strict_atoi_and_move_str_ptr(const char **str_ptr)
{
	unsigned int	res;

	res = 0;
	while (**str_ptr >= '0' && **str_ptr <= '9')
	{
		res = (res * 10) + (**str_ptr - '0');
		(*str_ptr)++;
	}
	return (res);
}

static size_t	ft_hex_itoa_len(size_t n)
{
	size_t	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	ft_hex_itoa_fill(size_t n, char *end_ptr, const char *hex_chars)
{
	*end_ptr = hex_chars[n % 16];
	if (n >= 16)
		ft_hex_itoa_fill(n / 16, end_ptr - 1, hex_chars);
}

char	*ft_hex_itoa(size_t n, bool is_uppercase)
{
	char	*ptr;
	size_t	len;

	len = ft_hex_itoa_len(n);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (is_uppercase)
		ft_hex_itoa_fill(n, &ptr[len - 1], g_hex_chars_u);
	else
		ft_hex_itoa_fill(n, &ptr[len - 1], g_hex_chars_l);
	return (ptr);
}
