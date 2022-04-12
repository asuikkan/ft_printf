/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:08:30 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/12 10:42:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_whitespace(char c)
{
	if (c == ' '
		||c == '\t'
		||c == '\n'
		||c == '\v'
		||c == '\f'
		||c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*str)
	{
		while (check_whitespace(*str))
			str++;
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (ft_isdigit(*str))
		{
			value = value * 10 + *str - '0';
			str++;
		}
		break ;
	}
	return (value * sign);
}
