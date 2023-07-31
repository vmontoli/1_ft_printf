/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:19 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/31 16:05:22 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO: Separar bonus de mantatory?
//TODO: Sacar futuro a libft a otra nueva carpeta pseudo libft2 make
//TODO: Y caracteres no printables??
//TODO: Hace falta pasar by reference un char*? Si se asigna un valor se guarda
//	localmente en la subfuncion o se guarda en la funcion principal?

//The functions that my ft_printf() call will take care of incrementing
//the variables:
//	va_list		ap;				[automatically done by va_arg]
//	const char	*fmt;			[passed by reference]
//	int			n_printed;		[passed by reference]
//such that the while loop can be looped without more modifications.
//When the end of fmt is reached, has to still point to the '\0' character.
int	ft_printf(const char *fmt, ...)
{
	int		n_printed;
	va_list	ap;

	va_start(ap, fmt);
	n_printed = 0;
	while (*fmt != '\0' && n_printed >= 0)
	{
		if (*fmt != '%')
			print_simple_char(&fmt, &n_printed);
		else
			print_conversion_specification(&fmt, &n_printed, ap);
	}
	va_end(ap);
	return (n_printed);
}

void	print_simple_char(const char **fmt_ptr, int *n_printed_ptr)
{
	write(1, *fmt_ptr, 1);
	(*fmt_ptr)++;
	(*n_printed_ptr)++;
}

void	print_conversion_specification(const char **fmt_ptr,
			int *n_printed_ptr, va_list ap)
{
	t_conv_mod	*conv_mod;
	t_conv_func	conv_func;

	conv_mod = (t_conv_mod *) ft_calloc(1, sizeof(t_conv_mod));
	(*fmt_ptr)++;
	get_conv_mod_flags(fmt_ptr, conv_mod);
	conv_mod->min_field_width = strict_atoi_and_move_str_ptr(fmt_ptr);
	get_printf_precision(fmt_ptr, conv_mod);
	conv_func = get_conversion_func(fmt_ptr);
	if (conv_func != printing_conversion_error)
		(*fmt_ptr)++;
	conv_func(ap, conv_mod, n_printed_ptr);
	free(conv_mod);
}
