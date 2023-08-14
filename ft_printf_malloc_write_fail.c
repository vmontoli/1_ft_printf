/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_malloc_write_fail.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:54:16 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/14 09:47:33 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	printf_did_malloc_fail(void *malloc_result, int *count_ptr)
{
	if (malloc_result != NULL)
		return (false);
	*count_ptr = -1;
	return (true);
}

bool	printf_did_write_fail(int write_result, int *count_ptr)
{
	if (write_result > -1)
		return (false);
	*count_ptr = -1;
	return (true);
}
