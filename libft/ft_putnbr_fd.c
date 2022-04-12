/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:55:47 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/25 14:16:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	remainder;

	remainder = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
		return ;
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	else
	{
		remainder = n % 10;
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(remainder + '0', fd);
}
