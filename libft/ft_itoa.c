/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:25:01 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/25 11:39:05 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_str(char *str, int n, size_t count, char sign)
{
	while (n != 0)
	{
		str[count - 1] = n % 10 + '0';
		count--;
		n /= 10;
	}
	if (sign)
		str[0] = sign;
	return (str);
}

static size_t	get_count(int n)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;
	char	sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (n < 0)
	{
		sign = '-';
		n *= -1;
	}
	count = get_count(n);
	if (sign)
		count++;
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	return (set_str(str, n, count, sign));
}
