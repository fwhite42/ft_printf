/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_parse.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/02/02 15:46:05 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 05:51:05 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_structures.h"
#include"ft_printf_utils.h"

int	ftpf_parse_flags(t_ftpf_fmt *format, const char **src)
{
	while (ftpf_is_flag(**src))
	{
		if (**src == '#')
			format->flag.alternate_form = 1;
		else if (**src == '-')
			format->flag.left_justify = 1;
		else if (**src == '+')
			format->flag.force_sign = 1;
		else if (**src == ' ')
			format->flag.space_b4_int = 1;
		else if (**src == '0')
			format->flag.zero_pad = 1;
		(*src)++;
	}
	return (1);
}

int	ftpf_parse_fmt(t_ftpf_fmt *fmt, const char **src)
{
	if (ftpf_is_flag(**src))
		ftpf_parse_flags(fmt, src);
	if (ftpf_is_digit(**src) && **src != '0')
		fmt->field_width = ftpf_read_number(src);
	if (**src == '.')
	{
		(*src)++;
		if (ftpf_is_digit(**src))
			fmt->precision = ftpf_read_number(src);
		else
			fmt->precision = 0;
	}
	if (ftpf_is_conversion_specifier(**src))
	{
		fmt->conversion = **src;
		(*src)++;
		return (1);
	}
	else
		return (ftpf_parse_fmt(fmt, src));
}
