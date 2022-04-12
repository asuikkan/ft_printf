/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:20:49 by asuikkan          #+#    #+#             */
/*   Updated: 2022/02/24 12:20:51 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize(t_form *form)
{
	form->output = NULL;
	form->pointer = NULL;
	form->sign = 0;
	form->char_flag = 0;
	form->short_flag = 0;
	form->long_flag = 0;
	form->long_long_flag = 0;
	form->long_double_flag = 0;
	form->prec_flag = 0;
	form->prec = 0;
	form->hash_flag = 0;
	form->space_flag = 0;
	form->zero_flag = 0;
	form->field_width = 0;
	form->dash_flag = 0;
	form->sign_flag = 0;
	form->null_c_flag = 0;
}

static void	init_jump_table(void (*jump_table[ARR_SIZE])(va_list, t_form*))
{
	jump_table['h'] = short_mod;
	jump_table['l'] = long_mod;
	jump_table['L'] = long_double_mod;
	jump_table['%'] = handle_percent;
	jump_table['#'] = handle_hash;
	jump_table[' '] = handle_space;
	jump_table['.'] = handle_precision;
	jump_table['-'] = handle_dash;
	jump_table['+'] = handle_sign;
	jump_table['0'] = handle_zero_pad;
	jump_table['f'] = handle_float;
	jump_table['c'] = handle_char;
	jump_table['s'] = handle_str;
	jump_table['p'] = handle_adr;
	jump_table['d'] = handle_int;
	jump_table['i'] = handle_int;
	jump_table['o'] = handle_octal;
	jump_table['u'] = handle_uint;
	jump_table['x'] = handle_hex;
	jump_table['X'] = handle_chex;
}

static int	form_check(va_list args, const char *format, int i, t_form *form)
{
	static void	(*jump_table[ARR_SIZE])(va_list, t_form*);

	init_jump_table(jump_table);
	if (format[++i] && (format[i] >= ' ' && format[i] <= 'z'))
	{
		while (format[i] && form->output == NULL)
		{
			while (ft_isdigit(format[i]))
			{
				if (format[i] == '0'
					&& (!form->field_width && !form->prec_flag))
					break ;
				if (form->prec_flag == 1)
					form->prec = form->prec * 10 + format[i++] - '0';
				else
					form->field_width = form->field_width * 10 \
						+ format[i++] - '0';
			}
			if (jump_table[(int)format[i]] != NULL)
				jump_table[(int)format[i]](args, form);
			i++;
		}
	}
	return (i);
}

static int	check_format(va_list args, const char *format, t_form *form)
{
	int	check;
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check = form_check(args, format, i, form);
			if (form->output != NULL)
			{
				print_output(form);
				initialize(form);
			}
			i = check;
		}
		else
		{
			form->ret += write(1, &format[i], 1);
			i++;
		}
	}
	return (form->ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_form		*form;
	int			ret;

	form = (t_form *)malloc(sizeof(t_form));
	if (form == NULL)
		exit(1);
	form->ret = 0;
	initialize(form);
	va_start(args, format);
	ret = check_format(args, format, form);
	va_end(args);
	free(form);
	return (ret);
}
