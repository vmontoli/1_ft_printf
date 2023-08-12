/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:28:39 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/12 21:39:18 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c
void	print_char_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	char	arg;

	(void) conv_mod;
	arg = (char) va_arg(ap, int);
	write(1, &arg, 1);
	(*n_printed_ptr)++;
}

// %s
void	print_str_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	char	*arg;

	(void) conv_mod;
	arg = va_arg(ap, char *);
	if (arg == NULL)
	{
		write(1, "(null)", 6);
		*n_printed_ptr += 6;
	}
	else
	{
		while (*arg != '\0')
		{
			write(1, arg, 1);
			(*n_printed_ptr)++;
			arg++;
		}
	}
}

// %%
void	print_percent_sign_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	(void) ap;
	(void) conv_mod;
	write(1, "%", 1);
	(*n_printed_ptr)++;
}
