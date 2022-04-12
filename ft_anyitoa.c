/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anyitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:29:09 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/02 15:29:10 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_count(unsigned long long nb, int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count++;
		nb /= base;
	}
	return (count);
}

char	*ft_anyitoa(unsigned long long nb, int base, int sign)
{
	char	*str;
	int		count;

	count = get_count(nb, base);
	if (sign == -1)
		count++;
	str = ft_strnew(count);
	if (str == NULL)
		exit(1);
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		if (nb % base < 10)
			str[--count] = nb % base + '0';
		else
			str[--count] = nb % base + 'a' - 10;
		nb /= base;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
