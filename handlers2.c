/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:42:07 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/24 15:42:10 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list args, t_form *form)
{
	char	temp;

	temp = (char)va_arg(args, int);
	if (temp == 0)
		form->null_c_flag = 1;
	form->output = ft_strnew(sizeof(char));
	form->output[0] = temp;
}

void	handle_str(va_list args, t_form *form)
{
	char	*temp;

	temp = va_arg(args, char *);
	if (temp == NULL)
		form->output = ft_strdup("(null)");
	else
	{
		form->output = ft_strdup(temp);
		if (form->prec_flag == 1)
		{
			temp = form->output;
			while (form->prec--)
				form->output++;
			ft_bzero(form->output, ft_strlen(form->output));
			form->output = temp;
		}
	}
}

void	handle_adr(va_list args, t_form *form)
{
	form->pointer = va_arg(args, void *);
	save_address(form);
}

void	handle_percent(va_list args, t_form *form)
{
	(void)args;
	form->output = ft_strdup("%");
}

void	handle_precision(va_list args, t_form *form)
{
	(void)args;
	form->prec_flag = 1;
}
