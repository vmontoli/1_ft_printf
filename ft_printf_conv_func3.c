/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:48:14 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/31 15:55:39 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %p TODO
void	print_ptr_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	char	arg;

	(void) conv_mod;
	arg = (char) va_arg(ap, int);
	write(1, &arg, 1);
	(*n_printed_ptr)++;
}

// %x TODO
void	print_hex_l_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	char	arg;

	(void) conv_mod;
	arg = (char) va_arg(ap, int);
	write(1, &arg, 1);
	(*n_printed_ptr)++;
}

// %X TODO
void	print_hex_u_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	char	arg;

	(void) conv_mod;
	arg = (char) va_arg(ap, int);
	write(1, &arg, 1);
	(*n_printed_ptr)++;
}
