/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:59:13 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/09 20:09:55 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	current;

	if (n >= 10)
		ft_putnbr_unsigned_fd((n / 10), fd);
	current = (n % 10) + '0';
	ft_putchar_fd(current, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_unsigned_fd((unsigned int) -n, fd);
	}
	else
		ft_putnbr_unsigned_fd((unsigned int) n, fd);
}
