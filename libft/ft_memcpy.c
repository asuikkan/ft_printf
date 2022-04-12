/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:36:24 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/17 11:33:56 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tempdest;
	const char	*tempsrc;

	if (!dest && !src)
		return (NULL);
	tempdest = (char *)dest;
	tempsrc = (const char *)src;
	while (n-- > 0)
	{
		*tempdest = *tempsrc;
		tempdest++;
		tempsrc++;
	}
	return (dest);
}
