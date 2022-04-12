/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:56:28 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/21 14:56:30 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fraction_to_str(t_dbl *dbl, char *str, int prec)
{
	int	count;

	count = prec + ft_strlen(str);
	if (dbl->frac_final == 0)
	{
		while (prec--)
			str[--count] = '0';
	}
	while (dbl->frac_final > 0)
	{
		while (prec-- > 15 + dbl->zeroes)
			str[--count] = '0';
		str[--count] = dbl->frac_final % 10 + '0';
		dbl->frac_final /= 10;
	}
	while (dbl->zeroes-- > 0)
		str[--count] = '0';
}

static void	integer_to_str(t_dbl *dbl, char *str, int prec, int sign)
{
	int	count;
	int	i;

	count = ft_count_digits(dbl->integer) + sign;
	i = 0;
	if (sign)
		str[i++] = '-';
	if (dbl->integer == 0)
		str[i] = '0';
	if (prec != 0)
		str[count] = '.';
	while (dbl->integer > 0)
	{
		str[--count] = dbl->integer % 10 + '0';
		dbl->integer /= 10;
	}
}

char	*form_str(t_dbl *dbl, int prec, int sign)
{
	char	*str;
	int		count;

	count = ft_count_digits(dbl->integer);
	str = ft_strnew(count + prec + sign + 1);
	if (str == NULL)
		exit(1);
	integer_to_str(dbl, str, prec, sign);
	fraction_to_str(dbl, str, prec);
	free(dbl);
	return (str);
}
