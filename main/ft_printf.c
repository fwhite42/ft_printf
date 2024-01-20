/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                             4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:48:11 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/20 15:33:05 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(char *src, ...)
{
	t_ftpf_fmt	format;
	int			bytes_written;
	va_list		args;

	va_start(args, src);
	while (*src)
	{
		if (ftpf_is_escape_char(*src))
		{
			ftpf_parse_fmt(&format, &src);
			if (!ftpf_print_fmt(format, args, &bytes_written))
				return (-1);
		}
		else
		{
			if (!ftpf_write_one(&bytes_written, current))
				return (-1);
			ftpf_read_one(&src);
		}
	}
	va_end(args);
	return (bytes_written);
}
