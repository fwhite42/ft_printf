/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_parsing_actions.c                                  4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:11:18 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/23 11:52:56 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_structures.h"
#include"ft_printf_constants.h"
#include"ft_printf_utils.h"
//dev
#include<stdio.h>

static inline void _reset_flag(t_ftpf_fmt *format)
{
	format->flag.alternate_form = 0;
	format->flag.left_justify = 0;
	format->flag.force_sign = 0;
	format->flag.space_b4_int = 0;
	format->flag.zero_pad = 0;
}

int	ftpf_parse_flags(t_ftpf_fmt *format, const char **src)
{
	int		i;
	char	flag;

	i = 0;
	_reset_flag(format);
	ftpf_read_one(&flag, src);
	while (ftpf_is_flag(flag))
	{
		if (flag == '#')
			format->flag.alternate_form = 1;
		else if ((flag) == '-')
			format->flag.left_justify = 1;
		else if (flag == '+')
			format->flag.force_sign = 1;
		else if (flag == ' ')
			format->flag.space_b4_int = 1;
		else if (flag == '0')
			format->flag.zero_pad = 1;
		ftpf_read_one(&flag, src);
		i++;
	}
	(*src)--;
	return (i);
}

int	ftpf_parse_field_width(t_ftpf_fmt *format, const char **src)
{
	format->field_width = ftpf_read_number(src);
	return (1);
}

int	ftpf_parse_precision(t_ftpf_fmt *format, const char **src)
{
	if (**src != '.')
	{
		format->precision = -1;
		return (-1);
	}
	else
	{
		(*src)++;
		format->precision = ftpf_read_number(src);
		if (format->precision == -1)
			format->precision = 0;
	}
	return (1);
}

