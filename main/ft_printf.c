/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                             4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:48:11 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/22 15:26:11 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf_parsers.h"
#include"ft_printf_printers.h"
#include<stdio.h>

int	ft_printf(char *src, ...)
{
	t_ftpf_fmt		format;
	t_ftpf_printer	print;
	int				bytes_written;
	va_list			args;

	va_start(args, src);
	bytes_written = 0;
	while (*src)
	{
		if (ftpf_is_escape_char(*src))
		{
			ftpf_parse_fmt(&format, &src);
			print = ftpf_load_printer(format.conversion);
			print(&format, args, &bytes_written);
		}
		else
		{
			if (!ftpf_write_one(&bytes_written, *src))
				return (-1);
			src++;
		}
	}
	va_end(args);
	return (bytes_written);
}
