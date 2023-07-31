/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:47:37 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/31 15:51:24 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d or %i
void	print_int_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	int		arg;
	char	*str;
	size_t	len;

	(void) conv_mod;
	arg = va_arg(ap, int);
	str = ft_itoa(arg);
	len = ft_strlen(str);
	write(1, str, len);
	*n_printed_ptr += len;
}

// %u
void	print_uint_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	unsigned int	arg;
	char			*str;
	size_t			len;

	(void) conv_mod;
	arg = va_arg(ap, unsigned int);
	str = ft_unsigned_itoa(arg);
	len = ft_strlen(str);
	write(1, str, len);
	*n_printed_ptr += len;
}
