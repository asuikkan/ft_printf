/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:25:23 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/19 11:41:59 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	char			*tempnew;
	size_t			len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	tempnew = new;
	while (*s1)
	{
		*tempnew = *s1;
		tempnew++;
		s1++;
	}
	ft_strcat(tempnew, s2);
	return (new);
}
