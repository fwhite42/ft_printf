/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/24 10:53:23 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 11:43:41 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include"libftprintf.h"

int	ft_vprintf(const char *src, va_list args)
{
	int				counter;
	t_ftpf_fmt		format;
	t_ftpf_printer	print;

	counter = 0;
	while (*src)
	{
		if (ftpf_is_escape_char(*src))
		{
			(src)++;
			ftpf_reset_format(&format);
			ftpf_parse_fmt(&format, &src);
			print = ftpf_load_printer(format.conversion);
			if (print == NULL)
				return (-1);
			print(&format, args, &counter);
		}
		else
			ftpf_write_one(&counter, *(src++));
		if (counter == -1)
			return (-1);
	}
	return (counter);
}

int	ft_printf(const char *src, ...)
{
	va_list			args;
	int				result;

	va_start(args, src);
	result = ft_vprintf(src, args);
	va_end(args);
	return (result);
}
