/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:17:45 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/12 21:57:28 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_conv_mod_flags(const char **fmt_ptr, t_conv_mod *conv_mod)
{
	while (**fmt_ptr == '#' || **fmt_ptr == '-' || **fmt_ptr == '0'
		|| **fmt_ptr == '+' || **fmt_ptr == ' ')
	{
		conv_mod->alt_form
			= conv_mod->alt_form || (**fmt_ptr == '#');
		conv_mod->left_adjusted
			= conv_mod->left_adjusted || (**fmt_ptr == '-');
		conv_mod->zero_padding
			= (conv_mod->zero_padding || (**fmt_ptr == '0'))
			&& !(conv_mod->left_adjusted);
		conv_mod->plus_before_positive
			= conv_mod->plus_before_positive || (**fmt_ptr == '+');
		conv_mod->space_before_positive
			= (conv_mod->space_before_positive || (**fmt_ptr == ' '))
			&& !(conv_mod->plus_before_positive);
		(*fmt_ptr)++;
	}
}

void	get_printf_precision(const char **fmt_ptr, t_conv_mod *conv_mod)
{
	conv_mod->precision_setted = (**fmt_ptr == '.');
	if (**fmt_ptr == '.')
	{
		(*fmt_ptr)++;
		conv_mod->precision = strict_atoi_and_move_str_ptr(fmt_ptr);
	}
}

t_conv_func	get_conversion_func(const char **fmt_ptr)
{
	if (**fmt_ptr == 'c')
		return (print_char_conversion);
	else if (**fmt_ptr == 's')
		return (print_str_conversion);
	else if (**fmt_ptr == 'p')
		return (print_ptr_conversion);
	else if (**fmt_ptr == 'd' || **fmt_ptr == 'i')
		return (print_int_conversion);
	else if (**fmt_ptr == 'u')
		return (print_uint_conversion);
	else if (**fmt_ptr == 'x')
		return (print_hex_l_conversion);
	else if (**fmt_ptr == 'X')
		return (print_hex_u_conversion);
	else if (**fmt_ptr == '%')
		return (print_percent_sign_conversion);
	return (printing_conversion_error);
}

void	printing_conversion_error(va_list ap, t_conv_mod *conv_mod,
			int *n_printed_ptr)
{
	(void) ap;
	(void) conv_mod;
	*n_printed_ptr *= -1;
}
