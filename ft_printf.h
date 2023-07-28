/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:51 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/28 21:47:54 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>		//NULL, size_t
# include <stdbool.h>		//bool, true, false
# include <stdarg.h>		//va_list, va_start, va_arg, va_copy, va_end
# include <stdlib.h>		//malloc, free
# include <unistd.h>		//write

//CONVersion MODifiers
/*
bool	left_adjusted;			//'-'
bool	zero_padding;			//'0'
bool	alt_form;				//'#'
bool	space_before_positive;	//' '
bool	plus_before_positive;	//'+'
int		min_field_width;		//number
int		precision;				//'.' and number
*/
typedef struct s_printf_conv_mod
{
	bool	left_adjusted;
	bool	zero_padding;
	bool	alt_form;
	bool	space_before_positive;
	bool	plus_before_positive;
	int		min_field_width;
	int		precision;
}	t_printf_conv_mod;

int		ft_printf(const char *format, ...);

void	ft_print_simple_char(const char **format_ptr, int *chars_printed_ptr);

void	ft_print_conversion_specification(const char **format_ptr,
			int *chars_printed_ptr, va_list ap);
#endif
