/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:20:48 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/01 14:20:54 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bzero_variables(unsigned char *ptr, char *adr)
{
	ft_bzero(ptr, sizeof(ptr));
	ft_bzero(adr, sizeof(ptr) * 2);
}

static char	*convert_to_char(char *temp)
{
	int	i;
	int	j;

	i = 2;
	j = -1;
	while (++j < 2)
	{
		if (temp[j] < 10)
			temp[j] = temp[j] + '0';
		else
			temp[j] = temp[j] + 'a' - 10;
	}
	return (temp);
}

void	save_address(t_form *form)
{
	unsigned char	ptr[sizeof(form->pointer)];
	char			adr[sizeof(form->pointer) * 2];
	int				i;
	int				j;
	char			temp[2];

	bzero_variables(ptr, adr);
	ft_memcpy(ptr, &form->pointer, sizeof(form->pointer));
	i = sizeof(form->pointer);
	j = 0;
	while (--i >= 0)
	{
		while (ptr[i] == '\0')
			i--;
		temp[0] = (ptr[i] >> 4) & 0xf;
		temp[1] = ptr[i] & 0xf;
		convert_to_char(temp);
		adr[j++] = temp[0];
		adr[j++] = temp[1];
	}
	form->output = ft_strnew((sizeof(form->pointer) * 2) + 2);
	if (form->output == NULL)
		return ;
	ft_memcpy(form->output, "0x", 2);
	ft_memcpy(form->output + 2, adr, sizeof(adr));
}
