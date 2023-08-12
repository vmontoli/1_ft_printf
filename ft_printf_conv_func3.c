/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:48:14 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/12 23:45:52 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %p
void	print_ptr_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	void	*arg;
	char	*str;
	size_t	len;

	(void) conv_mod;
	arg = (void *) va_arg(ap, void *);
	write(1, "0x", 2);
	str = ft_hex_itoa((size_t)arg, false);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	*n_printed_ptr += 2 + len;
}

// %x
void	print_hex_l_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	unsigned int	arg;
	char			*str;
	size_t			len;

	(void) conv_mod;
	arg = (unsigned int) va_arg(ap, int);
	str = ft_hex_itoa((size_t)arg, false);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	*n_printed_ptr += len;
}

// %X
void	print_hex_u_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	unsigned int	arg;
	char			*str;
	size_t			len;

	(void) conv_mod;
	arg = (unsigned int) va_arg(ap, int);
	str = ft_hex_itoa((size_t)arg, true);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	*n_printed_ptr += len;
}
