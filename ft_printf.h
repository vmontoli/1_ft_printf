/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:51 by vmontoli          #+#    #+#             */
/*   Updated: 2023/07/30 21:51:47 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>		//NULL, size_t
# include <stdbool.h>		//bool, true, false
# include <stdarg.h>		//va_list, va_start(), va_arg(), va_copy(), va_end()
# include <stdlib.h>		//malloc(), free()
# include <unistd.h>		//write()
# include "libft/libft.h"	//ft_calloc()

//CONVersion MODifiers
/*
bool	alt_form;				//'#'
bool	left_adjusted;			//'-'
bool	zero_padding;			//'0'
bool	plus_before_positive;	//'+'
bool	space_before_positive;	//' '
int		min_field_width;		//integer NOT STARTING WITH 0 (means '0' flag)
bool	precision_setted;		//'.'
int		precision;				//integer after '.'
 *
 * left_adjusted ('-') overrides zero_padding ('0')
 * plus_before_positive ('+') overrides space_before_positive (' ')
 * */
typedef struct s_conv_mod
{
	bool			alt_form;
	bool			left_adjusted;
	bool			zero_padding;
	bool			plus_before_positive;
	bool			space_before_positive;
	unsigned int	min_field_width;
	bool			precision_setted;
	unsigned int	precision;
}	t_conv_mod;

typedef void	(*t_conv_func)(va_list, t_conv_mod *, int *);

/***/

int				ft_printf(const char *fmt, ...);

void			print_simple_char(const char **fmt_ptr,
					int *n_printed_ptr);

void			print_conversion_specification(const char **fmt_ptr,
					int *n_printed_ptr, va_list ap);
void			get_conv_mod_flags(const char **fmt_ptr,
					t_conv_mod *conv_mod);
void			get_printf_precision(const char **fmt_ptr,
					t_conv_mod *conv_mod);
t_conv_func		get_conversion_func(const char **fmt_ptr);
void			printing_conversion_error(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

/***/

// %c
void			print_char_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %s
void			print_str_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %p
void			print_ptr_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %d or %i
void			print_int_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %u
void			print_uint_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %x
void			print_hex_l_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %X
void			print_hex_u_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

// %%
void			print_percent_sign_conversion(va_list ap, t_conv_mod *conv_mod,
					int *n_printed_ptr);

/***/

/*my strict rules: without initial spaces or signs (always positive, unsigned)*/
/*doesn't handle overflows*/
/*the str_ptr will end on the following caracter of the last digit*/
unsigned int	strict_atoi_and_move_str_ptr(const char **str_ptr);
#endif
