/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:36:18 by asuikkan          #+#    #+#             */
/*   Updated: 2021/12/20 14:36:19 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char			*new;
	char			*tempnew;
	char			*temps1;
	size_t			len;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	temps1 = s1;
	tempnew = new;
	while (*s1)
	{
		*tempnew = *s1;
		tempnew++;
		s1++;
	}
	ft_strcat(tempnew, s2);
	ft_strdel(&temps1);
	ft_strdel(&s2);
	return (new);
}
