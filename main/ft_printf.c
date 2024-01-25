/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/24 10:53:23 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/25 02:03:58 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf_parsers.h"
#include"ft_printf_printers.h"
#include<stdio.h>

static inline void	_reset_format(t_ftpf_fmt *format)
{
	format->flag.alternate_form = 0;
	format->flag.left_justify = 0;
	format->flag.force_sign = 0;
	format->flag.space_b4_int = 0;
	format->flag.zero_pad = 0;
	format->conversion = 0;
	format->field_width = -1;
	format->precision = -1;
}

static inline void	_ft_vprintf(const char *src, va_list args, int *counter)
{
	t_ftpf_fmt		format;
	t_ftpf_printer	print;

	while (*src)
	{
		if (ftpf_is_escape_char(*src))
		{
			(src)++;
			_reset_format(&format);
			ftpf_parse_fmt(&format, &src);
//			printf("force sign\t% i\n", format.flag.force_sign);
//			printf("zero pad\t% i\n", format.flag.zero_pad);
//			printf("space b4 int\t% i\n", format.flag.space_b4_int);
//			printf("alternate form\t% i\n", format.flag.alternate_form);
//			printf("left justify\t% i\n", format.flag.left_justify);
//			printf("precision\t% i\n", format.precision);
//			printf("field width\t% i\n", format.field_width);
//			printf("conversion\t %c\n", format.conversion);
			if (format.conversion != '%')
			{
				print = ftpf_load_printer(format.conversion);
				print(&format, args, counter);
//				printf("\n");
//				printf("force sign\t% i\n", format.flag.force_sign);
//				printf("zero pad\t% i\n", format.flag.zero_pad);
//				printf("space b4 int\t% i\n", format.flag.space_b4_int);
//				printf("alternate form\t% i\n", format.flag.alternate_form);
//				printf("left justify\t% i\n", format.flag.left_justify);
//				printf("precision\t% i\n", format.precision);
//				printf("field width\t% i\n", format.field_width);
//				printf("conversion\t %c\n", format.conversion);
			}
			else
				ftpf_write_one(counter, format.conversion);
		}
		else
		{
			if (!ftpf_write_one(counter, *src))
				return ;
			src++;
		}
	}
}

int	ft_printf(const char *src, ...)
{
	int				counter;
	va_list			args;

	va_start(args, src);
	counter = 0;
	_ft_vprintf(src, args, &counter);
	va_end(args);
	return (counter);
}
