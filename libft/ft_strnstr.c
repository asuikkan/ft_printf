/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:10:11 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/08 13:40:51 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	char	*tempstr;
	char	*tempsubstr;

	tempstr = (char *)str;
	tempsubstr = (char *)substr;
	if (!tempsubstr[0])
		return (tempstr);
	while (*tempstr && n)
	{
		if (!ft_strncmp(tempstr, tempsubstr, ft_strlen(tempsubstr))
			&& n >= ft_strlen(tempsubstr))
			return (tempstr);
		tempstr++;
		n--;
	}
	return (NULL);
}
