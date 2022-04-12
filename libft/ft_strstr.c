/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:38:08 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/08 12:14:20 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	char	*tempstr;
	char	*tempsubstr;

	tempstr = (char *)str;
	tempsubstr = (char *)substr;
	if (!tempsubstr[0])
		return (tempstr);
	while (*tempstr)
	{
		if (!ft_strncmp(tempstr, tempsubstr, ft_strlen(tempsubstr)))
			return (tempstr);
		tempstr++;
	}
	return (NULL);
}
