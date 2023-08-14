/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func_char_str.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:28:39 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/14 09:52:20 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c
void	print_char_conversion(va_list ap, t_conv_mod *conv_mod, int *count_ptr)
{
	char	arg;
	size_t	bytes_written;

	(void) conv_mod;
	arg = (char) va_arg(ap, int);
	bytes_written = write(1, &arg, 1);
	if (!printf_did_write_fail(bytes_written, count_ptr))
		*count_ptr += 1;
}

// %s
void	print_str_conversion(va_list ap, t_conv_mod *conv_mod, int *count_ptr)
{
	char	*arg;
	size_t	bytes_written;

	(void) conv_mod;
	arg = va_arg(ap, char *);
	if (arg == NULL)
	{
		bytes_written = write(1, "(null)", 6);
		if (!printf_did_write_fail(bytes_written, count_ptr))
			*count_ptr += 6;
	}
	else
	{
		while (*arg != '\0' && *count_ptr >= 0)
		{
			bytes_written = write(1, arg, 1);
			if (printf_did_write_fail(bytes_written, count_ptr))
				return ;
			*count_ptr += 1;
			arg++;
		}
	}
}

// %%
void	print_percent_sign_conversion(va_list ap, t_conv_mod *conv_mod,
			int *count_ptr)
{
	size_t	bytes_written;

	(void) ap;
	(void) conv_mod;
	bytes_written = write(1, "%", 1);
	if (!printf_did_write_fail(bytes_written, count_ptr))
		*count_ptr += 1;
}
