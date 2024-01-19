/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:17:11 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/19 14:43:50 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"

static inline void	_print_pointer(uintptr_t nbr, int *counter)
{
	while ((unsigned int)(nbr >> 32))
		_print_pointer(nbr >> 32, counter);
	ftpf_write_number_base(HEX_BASE_LC, nbr, counter);
}

static inline int precompue_bytes_to_be_written(uintptr_t nbr)
{

}

void	ftpf_print_p(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	uintptr_t	ptr;
	int			bytes_to_be_written;

	ptr = va_arg(args, uintptr_t);
	bytes_to_be_written = precompute_bytes_to_be_written(ptr);
	if (bytes_to_be_written < ftm->field_width)
		fptf_write_one(counter, ' ', fmt->field_witdth - bytes_to_be_written);
	ftpf_write_string(counter, "0x");
	_print_pointer(ptr, counter);
}
