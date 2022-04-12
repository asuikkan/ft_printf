/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:29:59 by asuikkan          #+#    #+#             */
/*   Updated: 2022/04/01 15:30:03 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_precision(t_form *form)
{
	char	*temp;
	int		i;
	int		count;

	count = form->prec - ft_strlen(form->output + form->sign * -1);
	temp = ft_strnew(form->prec + form->sign * -1);
	i = 0;
	if (form->output[0] == '-')
		temp[i++] = '-';
	while (i < count + form->sign * -1)
		temp[i++] = '0';
	ft_strcat(temp, form->output + form->sign * -1);
	ft_strdel(&form->output);
	form->output = temp;
}

void	sign_and_space(t_form *form)
{
	char	*temp;

	temp = ft_strnew(ft_strlen(form->output) + 1);
	if (form->sign_flag == 1)
		temp[0] = '+';
	else
		temp[0] = ' ';
	ft_strcat(temp, form->output);
	ft_strdel(&form->output);
	form->output = temp;
}

void	add_octal_form(t_form *form)
{
	char	*temp;

	temp = ft_strdup(form->output);
	ft_strdel(&form->output);
	form->output = ft_strjoin("0", temp);
	ft_strdel(&temp);
}

void	add_hex_form(t_form *form)
{
	char	*temp;

	temp = ft_strdup(form->output);
	ft_strdel(&form->output);
	form->output = ft_strjoin("0x", temp);
	ft_strdel(&temp);
}
