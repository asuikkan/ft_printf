/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:48:51 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/25 13:03:30 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	remainder;

	remainder = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
		return ;
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	else
	{
		remainder = n % 10;
		ft_putnbr(n / 10);
	}
	ft_putchar(remainder + '0');
}
