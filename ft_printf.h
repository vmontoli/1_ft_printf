/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:51 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/14 10:19:57 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>		//NULL, size_t
# include <stdbool.h>		//bool, true, false
# include <stdarg.h>		//va_list, va_start(), va_arg(), va_copy(), va_end()
# include <stdlib.h>		//malloc(), free()
# include <unistd.h>		//write()
# include "libft/libft.h"	//ft_memset(), ft_strlen(), ft_itoa(),
							// ft_unsigned_itoa()

//CONVersion MODifiers
/* csdupX%
bool	alt_form;				//'#': xX (0x or 0X before non-0 values)
bool	left_adjusted;			//'-'
bool	zero_padding;			//'0'
bool	plus_before_positive;	//'+': d (also w/ 0)
bool	space_before_positive;	//' ': d (also w/ 0)
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

//All the conv_func print_..._conversion() & printing_conversion_error()
//  functions signatures.
//Used to pass the functions reference from get_conversion_func() called by
//  get_conversion_specification().
typedef void	(*t_conv_func)(va_list, t_conv_mod *, int *);

/** PRINCIPAL FUNCTIONS **/
int				ft_printf(const char *fmt, ...);

void			print_simple_char(const char **fmt_ptr, int *count_ptr);

void			print_conversion_specification(const char **fmt_ptr,
					int *count_ptr, t_conv_mod *conv_mod, va_list ap);

/*Get the conversion characteristics*/
void			get_conv_mod_flags(const char **fmt_ptr, t_conv_mod *conv_mod);
void			get_printf_min_field_width(const char **fmt_ptr,
					t_conv_mod *conv_mod);
void			get_printf_precision(const char **fmt_ptr,
					t_conv_mod *conv_mod);
t_conv_func		get_conversion_func(const char **fmt_ptr);

/* print_..._conversion() and printing_conversion_error() */
// <error>
void			printing_conversion_error(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %c
void			print_char_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %s
void			print_str_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %p
void			print_ptr_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %d or %i
void			print_int_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %u
void			print_uint_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %x (l: lowercase)
void			print_hex_l_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %X (u: uppercase)
void			print_hex_u_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

// %%
void			print_percent_sign_conversion(va_list ap, t_conv_mod *conv_mod,
					int *count_ptr);

/*Helper functions: */

/*my strict rules of atoi:
 * without initial spaces or signs (always positive, unsigned)*/
/* doesn't handle overflows*/
/* the str_ptr will end pointing the following caracter of the last digit*/
unsigned int	strict_atoi_and_move_str_ptr(const char **str_ptr);

//itoa for hexadecimal format
char			*ft_hex_itoa(size_t n, bool is_uppercase);

//returns if the result on the input represents the fail state (NULL; -1)
// and changes count to -1.
bool			printf_did_malloc_fail(void *malloc_result, int *count_ptr);
bool			printf_did_write_fail(int write_result, int *count_ptr);

#endif
