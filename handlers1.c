/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:37:49 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/24 10:37:50 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int(va_list args, t_form *form)
{
	long long	value;

	value = va_arg(args, long long);
	if (form->char_flag == 1)
		value = (char)value;
	else if (form->short_flag == 1)
		value = (short)value;
	else if (form->long_flag == 1)
		value = (long)value;
	else if (form->long_long_flag == 0)
		value = (int)value;
	if (value < 0)
	{
		form->sign = -1;
		value *= -1;
	}
	form->output = ft_anyitoa(value, 10, form->sign);
	if (value == 0 && (form->prec_flag == 1 && form->prec == 0))
		ft_bzero(form->output, 1);
	if (form->prec && form->prec > (int)ft_strlen(form->output) + form->sign)
		add_precision(form);
	if ((form->space_flag == 1 || form->sign_flag == 1) && form->sign == 0)
		sign_and_space(form);
	if (form->prec_flag == 1 && form->zero_flag == 1)
		form->zero_flag = 0;
}

void	handle_uint(va_list args, t_form *form)
{
	int					base;
	unsigned long long	value;

	value = va_arg(args, unsigned long long);
	base = 10;
	if (value == 0 && (form->prec_flag == 1 && form->prec == 0))
		form->output = ft_strdup("");
	else if (form->char_flag == 1)
		form->output = ft_anyitoa((unsigned char)value, base, 0);
	else if (form->short_flag == 1)
		form->output = ft_anyitoa((unsigned short)value, base, 0);
	else if (form->long_flag == 1)
		form->output = ft_anyitoa((unsigned long)value, base, 0);
	else if (form->long_long_flag == 1)
		form->output = ft_anyitoa(value, base, 0);
	else
		form->output = ft_anyitoa((unsigned int)value, base, 0);
	if (form->prec && form->prec > (int)ft_strlen(form->output))
		add_precision(form);
	if (form->prec_flag == 1 && form->zero_flag == 1)
		form->zero_flag = 0;
}

void	handle_octal(va_list args, t_form *form)
{
	int					base;
	unsigned long long	value;

	value = va_arg(args, unsigned long long);
	base = 8;
	if (value == 0 && (form->prec_flag == 1 && form->prec == 0))
		form->output = ft_strdup("");
	else if (form->char_flag == 1)
		form->output = ft_anyitoa((unsigned char)value, base, 0);
	else if (form->short_flag == 1)
		form->output = ft_anyitoa((unsigned short)value, base, 0);
	else if (form->long_flag == 1)
		form->output = ft_anyitoa((unsigned long)value, base, 0);
	else if (form->long_long_flag == 1)
		form->output = ft_anyitoa(value, base, 0);
	else
		form->output = ft_anyitoa((unsigned int)value, base, 0);
	if (form->prec && form->prec > (int)ft_strlen(form->output))
		add_precision(form);
	if (form->hash_flag == 1)
		add_octal_form(form);
	if (form->prec_flag == 1 && form->zero_flag == 1)
		form->zero_flag = 0;
}

void	handle_hex(va_list args, t_form *form)
{
	int					base;
	unsigned long long	value;

	value = va_arg(args, unsigned long long);
	base = 16;
	if (value == 0 && (form->prec_flag == 1 && form->prec == 0))
		form->output = ft_strdup("");
	else if (form->char_flag == 1)
		form->output = ft_anyitoa((unsigned char)value, base, 0);
	else if (form->short_flag == 1)
		form->output = ft_anyitoa((unsigned short)value, base, 0);
	else if (form->long_flag == 1)
		form->output = ft_anyitoa((unsigned long)value, base, 0);
	else if (form->long_long_flag == 1)
		form->output = ft_anyitoa(value, base, 0);
	else
		form->output = ft_anyitoa((unsigned int)value, base, 0);
	if (form->prec && form->prec > (int)ft_strlen(form->output))
		add_precision(form);
	if (form->hash_flag == 1 && value != 0)
		add_hex_form(form);
	if (form->prec_flag == 1 && form->zero_flag == 1)
		form->zero_flag = 0;
}

void	handle_chex(va_list args, t_form *form)
{
	int					i;
	unsigned long long	value;

	value = va_arg(args, unsigned long long);
	if (value == 0 && (form->prec_flag == 1 && form->prec == 0))
		form->output = ft_strdup("");
	else if (form->char_flag == 1)
		form->output = ft_anyitoa((unsigned char)value, 16, 0);
	else if (form->short_flag == 1)
		form->output = ft_anyitoa((unsigned short)value, 16, 0);
	else if (form->long_flag == 1)
		form->output = ft_anyitoa((unsigned long)value, 16, 0);
	else if (form->long_long_flag == 1)
		form->output = ft_anyitoa(value, 16, 0);
	else
		form->output = ft_anyitoa((unsigned int)value, 16, 0);
	if (form->prec && form->prec > (int)ft_strlen(form->output))
		add_precision(form);
	if (form->hash_flag == 1 && value != 0)
		add_hex_form(form);
	i = -1;
	while (form->output[++i])
		form->output[i] = ft_toupper(form->output[i]);
	if (form->prec_flag == 1 && form->zero_flag == 1)
		form->zero_flag = 0;
}
