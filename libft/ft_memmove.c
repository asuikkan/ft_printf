/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:15:43 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/12 15:24:35 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned int		i;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	i = n;
	if (d < s)
	{
		ft_memcpy(d, s, n);
	}
	else
	{
		while (i)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
