/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf.c                                             4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/24 10:53:23 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 01:35:09 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ft_printf_parsers.h"
#include"ft_printf_printers.h"

static inline void	ftpf_reset_format(t_ftpf_fmt *format)
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
