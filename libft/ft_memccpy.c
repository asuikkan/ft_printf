/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:27:25 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/17 11:40:07 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long		lu;
	unsigned char		*tempdst;
	unsigned const char	*tempsrc;

	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned const char *)src;
	lu = 0;
	while (lu++ < n)
	{
		*tempdst = *tempsrc;
		if (*tempsrc == (unsigned char)c)
			return (tempdst + 1);
		tempdst++;
		tempsrc++;
	}
	return (NULL);
}
