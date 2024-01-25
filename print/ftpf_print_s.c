/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_s.c                                          4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:56:30 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/24 18:32:49 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"
#include<stdio.h>

static inline int	_precompute_length(t_ftpf_fmt *fmt, char *str)
{
	int len;

	if (str == NULL)
		len = 6;
	else
	{
		len = 0;
		while (str[len])
			len++;
	}
	if (fmt->precision > -1 && len > fmt->precision)
		return fmt->precision;
	return (len);
}

static inline void _compile_format(t_ftpf_fmt *fmt, char *str, char *pad)
{
	int length;
	
	length = _precompute_length(fmt, str);
	*pad = ' ';
	if (fmt->flag.left_justify)
		fmt->flag.zero_pad = 0;
	fmt->field_width -= length;
	if (fmt->flag.zero_pad)
		*pad = '0';
}

void	ftpf_print_s(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	char	*str;
	char	pad;

	str = va_arg(args, char *);
	_compile_format(fmt, str, &pad);
	if (str == NULL)
		str = "(null)";
	if (fmt->field_width > 0 && !fmt->flag.left_justify)
		ftpf_write_many(counter, pad, fmt->field_width);
	ftpf_write_string(counter, str, fmt->precision);
	if (fmt->field_width > 0 && fmt->flag.left_justify)
		ftpf_write_many(counter, pad, fmt->field_width);
}
