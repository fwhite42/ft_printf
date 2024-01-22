/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_s.c                                          4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:56:30 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/22 15:26:20 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"
#include<stdio.h>

static inline int	_precompute_bytes_to_be_written(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	ftpf_print_s(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	char	*str;
	int		bytes_to_be_written;

	str = va_arg(args, char *);
	bytes_to_be_written = _precompute_bytes_to_be_written(str);
	if (fmt->precision < bytes_to_be_written)
		bytes_to_be_written = fmt->precision;
	ftpf_write_string(counter, str, bytes_to_be_written);
}
