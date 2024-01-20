/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_p.c                                          ???              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:17:11 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/20 15:05:56 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"

static inline void	_print_pointer(uintptr_t nbr, int *counter)
{
	int	slot;

	slot = sizeof(unsigned int) * 8;
	while ((unsigned int)(nbr >> slot))
		_print_pointer(nbr >> slot, counter);
	ftpf_write_number_base(HEX_BASE_LC, nbr, counter);
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
