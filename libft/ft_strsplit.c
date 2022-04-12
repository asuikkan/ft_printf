/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:24:32 by asuikkan          #+#    #+#             */
/*   Updated: 2021/11/20 15:08:40 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**del_array(char **array, unsigned int i)
{
	while (i > 0)
	{
		ft_strdel(&array[i]);
		i--;
	}
	ft_strdel(&array[0]);
	free(array);
	array = NULL;
	return (array);
}

static unsigned int	get_count(const char *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] && (s[i] == c && s[i + 1] != c))
			|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static size_t	get_len(const char *s, char c, unsigned int i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*add_elem(const char *s, char c, unsigned int i)
{
	unsigned int	j;
	char			*elem;
	size_t			len;

	len = get_len(s, c, i);
	elem = ft_strnew(len);
	if (!elem)
		return (NULL);
	j = 0;
	while (j < len)
	{
		elem[j] = s[i];
		j++;
		i++;
	}
	return (elem);
}

char	**ft_strsplit(const char *s, char c)
{
	char			**str_array;
	unsigned int	i;
	unsigned int	j;

	str_array = (char **)malloc(sizeof(char *) * get_count(s, c) + 1);
	if (!str_array)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			str_array[j] = add_elem(s, c, i);
			if (!str_array[j])
				return (del_array(str_array, j));
			i += ft_strlen(str_array[j]);
			j++;
		}
	}
	str_array[j] = 0;
	return (str_array);
}
