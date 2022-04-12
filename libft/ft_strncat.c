/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:48:38 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/04 12:10:28 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char			*end;
	unsigned long	i;

	end = dest + ft_strlen(dest);
	i = 1;
	while (*src && i <= n)
	{
		*end = *src;
		end++;
		src++;
		i++;
	}
	*end = '\0';
	return (dest);
}
