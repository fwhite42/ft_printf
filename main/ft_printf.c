/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                             4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
*   Updated: 2024/01/23 19:11:16 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf_parsers.h"
#include"ft_printf_printers.h"
#include<stdio.h>

static inline int	_ft_vprintf(const char *src, va_list args)
{
	while (*src)
	{
		if (ftpf_is_escape_char(*src))
		{
			ftpf_parse_fmt(&format, &src);
			if (format.conversion != '%')
			{
				print = ftpf_load_printer(format.conversion);
				print(&format, args, &bytes_written);
			}
			else
				ftpf_write_one(&bytes_written, format.conversion);
		}
		else
		{
			if (!ftpf_write_one(&bytes_written, *src))
				return (-1);
			src++;
		}
	}
}

int	ft_printf(const char *src, ...)
{
	t_ftpf_fmt		format;
	t_ftpf_printer	print;
	int				bytes_written;
	va_list			args;

	va_start(args, src);
	bytes_written = 0;
	_ft_vprintf(src, args);
	va_end(args);
	return (bytes_written);
}
