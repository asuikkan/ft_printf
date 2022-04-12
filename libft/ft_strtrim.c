/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:10:42 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/19 13:17:56 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	if (c == ' '
		|| c == '\n'
		|| c == '\t')
		return (1);
	return (0);
}

static int	end_whitespace(const char *s, unsigned int i)
{
	while (s[i])
	{
		if (!whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static size_t	get_len(const char *s, unsigned int i)
{
	size_t	len;

	len = 0;
	while (s[i])
	{
		if (whitespace(s[i]))
		{
			if (end_whitespace(s, i))
				break ;
		}
		len++;
		i++;
	}
	return (len);
}

char	*ft_strtrim(const char *s)
{
	char			*trim;
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (whitespace(s[i]))
		i++;
	len = get_len(s, i);
	trim = ft_strnew(len);
	if (!trim)
		return (NULL);
	j = 0;
	while (j < len)
	{
		trim[j] = s[i];
		i++;
		j++;
	}
	return (trim);
}
