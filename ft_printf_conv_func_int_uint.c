/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_func_int_uint.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:47:37 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/13 23:27:44 by vmontoli         ###   ########.fr       */
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
	size_t	bytes_written;

	(void) conv_mod;
	arg = va_arg(ap, int);
	str = ft_itoa(arg);
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

// %u
void	print_uint_conversion(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	unsigned int	arg;
	char			*str;
	size_t			len;
	size_t			bytes_written;

	(void) conv_mod;
	arg = va_arg(ap, unsigned int);
	str = ft_unsigned_itoa(arg);
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
