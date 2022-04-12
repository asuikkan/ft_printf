/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:14:54 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/04 11:23:28 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*end;

	end = dest + ft_strlen(dest);
	while (*src)
	{
		*end = *src;
		end++;
		src++;
	}
	*end = '\0';
	return (dest);
}
