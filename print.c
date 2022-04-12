/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:26:44 by asuikkan          #+#    #+#             */
/*   Updated: 2022/02/25 11:26:57 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_zeroes(t_form *form, char *temp)
{
	int		i;
	int		count;
	char	*start;

	start = form->output;
	count = form->field_width - ft_strlen(form->output);
	i = 0;
	while (!ft_isdigit(*form->output))
		temp[i++] = *form->output++;
	if (form->hash_flag == 1 && *form->output == '0')
	{
		temp[i++] = *form->output++;
		if (*form->output == 'x' || *form->output == 'X')
			temp[i++] = *form->output++;
	}
	while (count)
	{
		temp[i++] = '0';
		count--;
	}
	ft_strcat(temp, form->output);
	form->output = start;
	return (temp);
}

static void	add_padding(t_form *form, int len)
{
	char	*temp;
	int		count;

	temp = ft_strnew(form->field_width);
	if (form->dash_flag == 1)
	{
		ft_memmove(temp, form->output, len);
		while (form->field_width-- > len)
			temp[form->field_width] = ' ';
	}
	else
	{
		if (form->zero_flag == 1)
			temp = add_zeroes(form, temp);
		else
		{
			count = form->field_width - len;
			while (count--)
				temp[count] = ' ';
			ft_strcat(temp, form->output);
		}
	}
	ft_strdel(&form->output);
	form->output = temp;
}

void	print_output(t_form *form)
{
	int		len;

	len = ft_strlen(form->output);
	if (form->field_width && form->field_width > len)
		add_padding(form, len);
	if (form->null_c_flag == 1)
	{
		if (ft_strlen(form->output))
			form->ret += write(1, form->output, ft_strlen(form->output) - 1);
		form->ret += write(1, "\0", 1);
	}
	else
		form->ret += write(1, form->output, ft_strlen(form->output));
	ft_strdel(&form->output);
}
