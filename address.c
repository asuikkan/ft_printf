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

static void	bits_to_char(char *temp, unsigned char c)
{
	int	i;
	int	j;

	temp[0] = (c >> 4) & 0xf;
	temp[1] = c & 0xf;
	i = 2;
	j = -1;
	while (++j < 2)
	{
		if (temp[j] < 10)
			temp[j] = temp[j] + '0';
		else
			temp[j] = temp[j] + 'a' - 10;
	}
}

void	save_address(t_form *form)
{
	unsigned char	ptr[sizeof(form->pointer)];
	int				i;
	int				j;
	char			temp[2];

	ft_bzero(ptr, sizeof(ptr));
	ft_memcpy(ptr, &form->pointer, sizeof(form->pointer));
	form->output = ft_strnew((sizeof(form->pointer) * 2) + 2);
	if (form->output == NULL)
		exit(1);
	ft_memcpy(form->output, "0x", 2);
	i = sizeof(form->pointer);
	j = 2;
	while (--i >= 0)
	{
		while (i > 0 && ptr[i] == '\0')
			i--;
		bits_to_char(temp, ptr[i]);
		if (temp[0] == '0' && j == 2)
			;
		else
			form->output[j++] = temp[0];
		form->output[j++] = temp[1];
	}
}
