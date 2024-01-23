/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_p.c                                          4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:17:11 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/23 19:08:19 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"
#include<stdio.h>

static inline void	_print_pointer(uintptr_t nbr, int *counter)
{
	if ((nbr >> 8))
	{
		_print_pointer(nbr >> 8, counter);
		if (nbr % 256 < 16)
			ftpf_write_one(counter, '0');
	}
	ftpf_write_number_base(HEX_BASE_LC, (unsigned int)(nbr % 256), counter);
}

void	ftpf_print_p(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	uintptr_t	ptr;
	int			bytes_to_be_written;

	ptr = va_arg(args, uintptr_t);
	bytes_to_be_written = sizeof(uintptr_t) + 2;
	if (bytes_to_be_written < fmt->field_width)
		ftpf_write_many(counter, ' ', fmt->field_width - bytes_to_be_written);
	ftpf_write_string(counter, "0x", 2);
	_print_pointer(ptr, counter);
}
