/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_c.c                                          4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:51:13 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/20 16:20:32 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"

void	ftpf_print_c(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	char		data;

	if (fmt->field_width && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
	data = va_arg(args, int);
	ftpf_write_one(counter, data);
	if (fmt->field_width && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
}
