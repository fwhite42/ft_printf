/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_u.c                                          4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:52:23 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/24 16:38:39 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"

static inline int	_compute_number_of_digits(unsigned int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static inline void	_compile_format(t_ftpf_fmt *fmt, int nbr)
{
	int length;
	int has_precision;
	
	length = _compute_number_of_digits(nbr);
	has_precision = 0;
	if (fmt->precision > -1)
		has_precision = 1;
	fmt->precision -= length;
	if (fmt->precision > 0)
		fmt->field_width -= fmt->precision;
	fmt->field_width -= length;
	if (fmt->flag.zero_pad == 1 && !has_precision)
	{
		fmt->precision = fmt->field_width;
		fmt->field_width = -1; 
	}
}

void	ftpf_print_u(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	_compile_format(fmt, nbr);
	if (fmt->field_width > 0 && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
	if (fmt->precision > 0)
		ftpf_write_many(counter, '0', fmt->precision);
	ftpf_write_number_base(NBR_BASE, nbr, counter);
	if (fmt->field_width > 0 && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
}
