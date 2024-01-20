/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_u.c                                          ???              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:52:23 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/20 15:12:13 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"

static inline int	_precompute_bytes_to_write(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr != nbr % 10)
	{
		i++;
		nbr = nbr % 10;
	}
	return (i);
}

void	ftpf_print_d(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	unsigned int	nbr;
	int				bytes_to_write;

	nbr = va_arg(args, unsigned int);
	bytes_to_write = _precompute_bytes_to_write(nbr);
	if (fmt->precision > bytes_to_write)
		bytes_to_write = fmt->precision;
	if (fmt->field_width > bytes_to_write && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - bytes_to_write);
	if (fmt->precision > bytes_to_write)
		ftpf_write_many(counter, '0', fmt->precision - bytes_to_write);
	ftpf_write_number_base(NBR_BASE, nbr, counter);
	if (fmt->field_width > bytes_to_write && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - bytes_to_write);
}
