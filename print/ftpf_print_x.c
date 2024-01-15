/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:19:27 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 19:50:28 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<ft_printf_structures.h>
#include<ft_printf_constants.h>

void	ftpf_print_x(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	unsigned int	data;
	unsigned int	number_of_characters;

	data = va_arg(args, unsigned int);
	number_of_characters = ftpf_precompute_number_of_characters(data, 16, 0);
	if (fmt.alternate_form)
		ftpf_write_string(counter, "0x");
	if (fmt.precision > number_of_characters)
	{
		ftpf_write_many('0', fmt.precision - number_of_characters);
		number_of_characters = fmt.precision;
		if (fmt.alternate_form)
			number_of_characters += 2;
	}
	if (fmt.field_width > number_of_characters)
	{
		ftpf_write_many(' ', fmt.field_width - number_of_characters);
	}
	ftpf_write_number_base(counter, HEX_BASE_LC, 16, data);
}
