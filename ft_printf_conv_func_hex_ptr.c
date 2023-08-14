/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func_hex_ptr.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:48:14 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/14 03:35:37 by vmontoli         ###   ########.fr       */
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
	size_t	bytes_written;

	(void) conv_mod;
	arg = (void *) va_arg(ap, void *);
	bytes_written = write(1, "0x", 2);
	if (bytes_written == 2)
		*n_printed_ptr += 2;
	else
	{
		*n_printed_ptr = -1;
		return ;
	}
	str = ft_hex_itoa((size_t)arg, false);
	if (str == NULL)
	{
		*n_printed_ptr = -1;
		return ;
	}
	len = ft_strlen(str);
	bytes_written = write(1, str, len);
	if (bytes_written == len)
		*n_printed_ptr += len;
	else
		*n_printed_ptr = -1;
	free(str);
}

// %x
void	print_hex_l_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	unsigned int	arg;
	char			*str;
	size_t			len;
	size_t			bytes_written;

	arg = (unsigned int) va_arg(ap, int);
	if (arg != 0 && conv_mod->alt_form)
	{
		bytes_written = write(1, "0x", 2);
		if (bytes_written == 2)
			*n_printed_ptr += 2;
		else
		{
			*n_printed_ptr = -1;
			return ;
		}
	}
	str = ft_hex_itoa((size_t)arg, false);
	if (str == NULL)
	{
		*n_printed_ptr = -1;
		return ;
	}
	len = ft_strlen(str);
	bytes_written = write(1, str, len);
	if (bytes_written == len)
		*n_printed_ptr += len;
	else
		*n_printed_ptr = -1;
	free(str);
}

// %X
void	print_hex_u_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	unsigned int	arg;
	char			*str;
	size_t			len;
	size_t			bytes_written;

	(void) conv_mod;
	arg = (unsigned int) va_arg(ap, int);
	if (arg != 0 && conv_mod->alt_form)
	{
		bytes_written = write(1, "0X", 2);
		if (bytes_written == 2)
			*n_printed_ptr += 2;
		else
		{
			*n_printed_ptr = -1;
			return ;
		}
	}
	str = ft_hex_itoa((size_t)arg, true);
	if (str == NULL)
	{
		*n_printed_ptr = -1;
		return ;
	}
	len = ft_strlen(str);
	bytes_written = write(1, str, len);
	if (bytes_written == len)
		*n_printed_ptr += len;
	else
		*n_printed_ptr = -1;
	free(str);
}
