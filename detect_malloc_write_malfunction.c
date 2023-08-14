/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_malloc_write_malfunction.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:54:16 by vmontoli          #+#    #+#             */
/*   Updated: 2023/08/14 08:09:35 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	did_malloc_fail(void *malloc_result, int *n_printed_ptr)
{
	if (malloc_result == NULL)
	{
		*n_printed_ptr = -1;
		return (true);
	}
	return (false);
}

bool	did_write_fail(int write_result, int *n_printed_ptr)
{
	if (write_result == -1)
	{
		*n_printed_ptr = -1;
		return (true);
	}
	return (false);
}
