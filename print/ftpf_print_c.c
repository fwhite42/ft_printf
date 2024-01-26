/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_c.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 18:09:17 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 18:09:23 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"
#include<stdio.h>

void	ftpf_print_c(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	char		data;

	if (fmt->field_width > -1 && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
	data = va_arg(args, int);
	ftpf_write_one(counter, data);
	if (fmt->field_width > -1 && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
}
