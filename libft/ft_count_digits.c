/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:51:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/21 11:51:22 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(long long nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
