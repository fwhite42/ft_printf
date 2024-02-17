/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_escape.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 17:56:50 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 06:01:21 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"
#include"ft_printf_utils.h"
#include<stdarg.h>

void	ftpf_print_escape(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	(void) args;
	if (fmt->field_width > -1 && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
	ftpf_write_one(counter, '%');
	if (fmt->field_width > -1 && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
}
