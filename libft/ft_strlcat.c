/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:10:15 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/04 14:36:06 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t destsize)
{
	size_t	remaining;
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	remaining = destsize;
	while (*dest && remaining)
	{
		dest++;
		remaining--;
	}
	if (*dest)
		return (destsize + srclen);
	destlen = destsize - remaining;
	while (*src && remaining > 1)
	{
		*dest = *src;
		dest++;
		remaining--;
		src++;
	}
	*dest = '\0';
	return (destlen + srclen);
}
