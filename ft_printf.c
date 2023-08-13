/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:19 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/13 23:02:44 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO: el Makefile deberia poder mandar recompilar el libft y que solo copie el
//  archivo y continue compilando (haga la llamada a ar si no hay otras
//  modificaciones en otros arhivos) si no hay nada que hacer
//TODO: el libft deberia estar bien de bien protegidos writes y mallocs y que
//  devuelvan valores aunque estuvieran originalmente concebidos como void
//  porque total el resultado con ignorarlo funciona igual.
//TODO: Separar bonus de mantatory?
//TODO: Y caracteres no printables??
//TODO: Hace falta pasar by reference un char*? Si se asigna un valor se guarda
//	localmente en la subfuncion o se guarda en la funcion principal?

//The functions that my ft_printf() call will take care of incrementing
//the variables:
//	va_list		ap;				[automatically done by va_arg]
//	const char	*fmt;			[passed by reference]
//	int			n_printed;		[passed by reference]
//and zeroing its contents to reuse:
//  t_conv_mod	*conv_mod;		[passed as value]
//so the while loop of ft_printf() can be looped without more modifications.
//When the end of fmt is reached, has to still point to the '\0' character.
int	ft_printf(const char *fmt, ...)
{
	t_conv_mod	*conv_mod;
	va_list		ap;
	int			n_printed;

	conv_mod = malloc(sizeof(t_conv_mod));
	if (conv_mod == NULL)
		return (-1);
	va_start(ap, fmt);
	n_printed = 0;
	while (*fmt != '\0' && n_printed >= 0)
	{
		if (*fmt != '%')
			print_simple_char(&fmt, &n_printed);
		else
			print_conversion_specification(&fmt, &n_printed, conv_mod, ap);
	}
	va_end(ap);
	free(conv_mod);
	return (n_printed);
}

void	print_simple_char(const char **fmt_ptr, int *n_printed_ptr)
{
	size_t	bytes_written;

	bytes_written = write(1, *fmt_ptr, 1);
	if (bytes_written == 1)
	{
		*fmt_ptr += 1;
		*n_printed_ptr += 1;
	}
	else
		*n_printed_ptr = -1;
}

void	print_conversion_specification(const char **fmt_ptr,
			int *n_printed_ptr, t_conv_mod *conv_mod, va_list ap)
{
	t_conv_func	conv_func;

	ft_memset(conv_mod, 0, sizeof(t_conv_mod));
	*fmt_ptr += 1;
	get_conv_mod_flags(fmt_ptr, conv_mod);
	conv_mod->min_field_width = strict_atoi_and_move_str_ptr(fmt_ptr);
	get_printf_precision(fmt_ptr, conv_mod);
	conv_func = get_conversion_func(fmt_ptr);
	if (conv_func != printing_conversion_error)
		*fmt_ptr += 1;
	conv_func(ap, conv_mod, n_printed_ptr);
}
