/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:19 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/29 17:44:24 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO: Y si termina en un porcentaje sin nada mas?
//TODO: Y si un porcentaje continua con caracteres que no cuadran?
//TODO: Y caracteres no printables??
//TODO: Hace falta pasar by reference un char*? Si se asigna un valor se guarda
//	localmente en la subfuncion o se guarda en la funcion principal?

//The functions that my ft_printf() call will take care of incrementing
//the variables:
//	va_list		ap;				[automatically done by va_arg]
//	const char	*fmt;			[passed by reference]
//	int			n_char_printed;	[passed by reference]
//such that the while loop can be looped without more modifications.
//When the end of fmt is reached, has to still point to the '\0' character.
int	ft_printf(const char *fmt, ...)
{
	int		n_char_printed;
	va_list	ap;

	va_start(ap, fmt);
	n_char_printed = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			print_simple_char(&fmt, &n_char_printed);
		else
			print_conversion_specification(&fmt, &n_char_printed, ap);
	}
	va_end(ap);
	return (n_char_printed);
}

void	print_simple_char(const char **fmt_ptr, int *n_char_printed_ptr)
{
	write(1, *fmt_ptr, 1);
	(*fmt_ptr)++;
	(*n_char_printed_ptr)++;
}

//TODO
void	print_conversion_specification(const char **fmt_ptr,
			int *n_char_printed_ptr, va_list ap)
{
	t_printf_conv_mod	*conv_mod;

	(void) n_char_printed_ptr;
	(void) ap;
	conv_mod = (t_printf_conv_mod *) malloc(sizeof(t_printf_conv_mod));
	(*fmt_ptr)++;
	get_conv_mod_flags(fmt_ptr, conv_mod);
	conv_mod->min_field_width = atoi_strict_moving_str_ptr(fmt_ptr);
	free(conv_mod);
}

void	get_conv_mod_flags(const char **fmt_ptr,
			t_printf_conv_mod *conv_mod)
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

unsigned int	atoi_strict_moving_str_ptr(const char **str_ptr)
{
	unsigned int	res;

	while (**str_ptr >= '0' && **str_ptr <= '9')
	{
		res = (res * 10) + (**str_ptr - '0');
		(*str_ptr)++;
	}
	return (res);
}
