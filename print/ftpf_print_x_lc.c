/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_x_lc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:19:27 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/19 15:54:34 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<ft_printf_structures.h>
#include<ft_printf_constants.h>

static inline int	_precompute_bytes_to_write(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr != nbr % 16)
	{
		i++;
		nbr = nbr % 16;
	}
	return (i);
}

void	ftpf_print_x(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	unsigned int	nbr;
	unsigned int	bytes_to_write;

	nbr = va_arg(args, unsigned int);
	bytes_to_write = _precompute_bytes_to_write(nbr, 16, 0);
	if (fmt->precision > bytes_to_write)
		bytes_to_write = fmt->precision;
	if ((fmt->flag).alterante_form)
		bytes_to_write += 2;
	if (fmt->field_width > bytes_to_write && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->filed_width - bytes_to_write);
	if (fmt.alternate_form)
		ftpf_write_string(counter, "0x");
	if (fmt.precision > bytes_to_write)
	{
		if (fmt.alternate_form)
			bytes_to_write -= 2;
		ftpf_write_many('0', fmt.precision - bytes_to_write);
	}
	ftpf_write_number_base(HEX_BASE_LC, nbr, counter);
	if (fmt->field_width > bytes_to_write && (fmt->flags).left_justify)
		ftpf_write_many(' ', fmt.field_width - field_width);
}
