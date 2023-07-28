/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:19 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/28 21:47:59 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO: Y si termina en un porcentaje sin nada mas?
//TODO: Y si un porcentaje continua con caracteres que no cuadran?
//TODO: Y caracteres no printables??
//TODO: Hace falta pasar by reference un char*? Si se asigna un valor se guarda
//	localmente en la subfuncion o se guarda en la funcion principal?
//TODO: Mirar lo de pointers (multiples) y const

//The functions that my ft_printf() call will take care of incrementing
//the variables:
//	va_list		ap;				[automatically done by va_arg]
//	const char	*format;		[passed by reference]
//	int			chars_printed;	[passed by reference] #TODO: by reference?
//such that the while loop can be looped without more modifications.
//When the end of format is reached, has to still point to the '\0' character.
int	ft_printf(const char *format, ...)
{
	int		chars_printed;
	va_list	ap;

	va_start(ap, format);
	chars_printed = 0;
	while (*format != '\0')
	{
		if (*format != '%')
			ft_print_simple_char(&format, &chars_printed);
		else
			ft_print_conversion_specification(&format, &chars_printed, ap);
	}
	va_end(ap);
	return (chars_printed);
}

void	ft_print_simple_char(const char **format_ptr, int *chars_printed_ptr)
{
	write(1, *format_ptr, 1);
	(*format_ptr)++;
	(*chars_printed_ptr)++;
}

//TODO
void	ft_print_conversion_specification(const char **format_ptr,
			int *chars_printed_ptr, va_list ap)
{
	t_printf_conv_mod	*conv_mod;

	conv_mod = (t_printf_conv_mod *) malloc(sizeof(t_printf_conv_mod));
	&format_ptr++;
}
