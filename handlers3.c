/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:33:56 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/30 13:34:00 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hash(va_list args, t_form *form)
{
	(void)args;
	form->hash_flag = 1;
}

void	handle_zero_pad(va_list args, t_form *form)
{
	(void)args;
	form->zero_flag = 1;
}

void	handle_space(va_list args, t_form *form)
{
	(void)args;
	form->space_flag = 1;
}

void	handle_dash(va_list args, t_form *form)
{
	(void)args;
	form->dash_flag = 1;
}

void	handle_float(va_list args, t_form *form)
{
	char	*temp;

	if (form->prec_flag == 0)
		form->prec = 6;
	if (form->long_double_flag == 1)
		form->output = ft_ftoa(va_arg(args, long double), form->prec);
	else
		form->output = ft_ftoa(va_arg(args, double), form->prec);
	if (form->hash_flag == 1 && form->prec == 0)
	{
		temp = ft_strdup(form->output);
		ft_strdel(&form->output);
		form->output = ft_strjoin(temp, ".");
		ft_strdel(&temp);
	}
	if ((form->space_flag == 1 || form->sign_flag == 1)
		&& form->output[0] != '-')
		sign_and_space(form);
}
