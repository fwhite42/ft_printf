/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_escape.c                                     4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:51:13 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/25 12:32:02 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"
#include<stdio.h>

void	ftpf_print_escape(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	(void) args;
	if (fmt->field_width > -1 && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
	ftpf_write_one(counter, '%');
	if (fmt->field_width > -1 && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
}
