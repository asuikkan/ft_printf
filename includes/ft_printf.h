/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:18:05 by asuikkan          #+#    #+#             */
/*   Updated: 2022/02/24 12:18:08 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

/* For handling flag jump table */
# define ARR_SIZE			127

/* For handling floats */
# define SIXTY_FOURTH_BIT	0x8000000000000000
# define FIFTY_TWO_BITS		0xFFFFFFFFFFFFF
# define FIFTY_THREE_BITS	0x1FFFFFFFFFFFFF
# define ELEVEN_BITS		0x7FF
# define FIFTY_THIRD_BIT	0x10000000000000
# define EXP_BIAS			1023

/* Struct for modifiers and specifiers */
typedef struct s_form
{
	char	*output;
	void	*pointer;
	int		ret;
	int		sign;
	int		char_flag;
	int		short_flag;
	int		long_flag;
	int		long_long_flag;
	int		long_double_flag;
	int		prec_flag;
	int		prec;
	int		hash_flag;
	int		space_flag;
	int		zero_flag;
	int		field_width;
	int		dash_flag;
	int		sign_flag;
	int		null_c_flag;
}			t_form;

/* Union to save double bit structure */
typedef union u_convert
{
	long long	pattern;
	double		number;
}				t_convert;

/* Struct for float handling */
typedef struct s_dbl
{
	unsigned long long	integer;
	unsigned long long	fraction;
	unsigned long long	frac_final;
	int					zeroes;
}				t_dbl;

int		ft_printf(const char *format, ...);
void	print_output(t_form *form);
int		pf_toupper(int c);
int		pf_isdigit(int c);
char	*ft_anyitoa(unsigned long long nb, int base, int sign);
char	*ft_ftoa(double nb, int prec);
char	*form_str(t_dbl *dbl, int prec, int sign);
char	*pf_strdup(const char *src);
char	*pf_strjoin(const char *s1, const char *s2);
char	*pf_strcat(char *dest, const char *src);
char	*pf_strnew(size_t size);
size_t	pf_strlen(const char *str);
size_t	pf_count_digits(long long nb);
void	pf_strdel(char **as);
void	pf_bzero(void *s, size_t n);
void	add_precision(t_form *form);
void	add_octal_form(t_form *form_str);
void	add_hex_form(t_form *form);
void	sign_and_space(t_form *form);
void	save_address(t_form *form);
void	char_mod(va_list args, t_form *form);
void	short_mod(va_list args, t_form *form);
void	long_mod(va_list args, t_form *form);
void	long_long_mod(va_list args, t_form *form);
void	long_double_mod(va_list args, t_form *form);
void	handle_percent(va_list args, t_form *form);
void	handle_hash(va_list args, t_form *form);
void	handle_space(va_list args, t_form *form);
void	handle_precision(va_list args, t_form *form);
void	handle_dash(va_list args, t_form *form);
void	handle_sign(va_list args, t_form *form);
void	handle_zero_pad(va_list args, t_form *form);
void	handle_digit(va_list args, t_form *form);
void	handle_float(va_list args, t_form *form);
void	handle_int(va_list args, t_form *form);
void	handle_uint(va_list args, t_form *form);
void	handle_octal(va_list args, t_form *form);
void	handle_hex(va_list args, t_form *form);
void	handle_chex(va_list args, t_form *form);
void	handle_char(va_list args, t_form *form);
void	handle_str(va_list args, t_form *form);
void	handle_adr(va_list args, t_form *form);
void	*pf_memmove(void *dest, const void *src, size_t n);
void	*pf_memcpy(void *dest, const void *src, size_t n);
void	*pf_memset(void *str, int c, size_t n);

#endif
