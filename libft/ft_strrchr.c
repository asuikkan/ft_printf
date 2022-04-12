/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:33:12 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/04 16:40:24 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;
	char	*found;

	found = NULL;
	temp = (char *)str;
	while (*temp)
	{
		if (*temp == c)
			found = temp;
		temp++;
	}
	if (*temp == c)
		found = temp;
	return (found);
}
