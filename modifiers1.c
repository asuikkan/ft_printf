/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:49:25 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/22 14:49:27 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_mod(va_list args, t_form *form)
{
	(void) args;
	form->char_flag = 1;
}

void	short_mod(va_list args, t_form *form)
{
	(void) args;
	if (form->short_flag)
	{
		form->short_flag = 0;
		char_mod(args, form);
	}
	else
		form->short_flag = 1;
}

void	long_long_mod(va_list args, t_form *form)
{
	(void) args;
	form->long_long_flag = 1;
}

void	long_mod(va_list args, t_form *form)
{
	(void) args;
	if (form->long_flag)
	{
		form->long_flag = 0;
		long_long_mod(args, form);
	}
	else
		form->long_flag = 1;
}

void	long_double_mod(va_list args, t_form *form)
{
	(void) args;
	form->long_double_flag = 1;
}
