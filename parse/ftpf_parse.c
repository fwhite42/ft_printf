/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_parse.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/20 15:37:57 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/25 13:26:51 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"
#include<stdio.h>

//==============================================================================
//	Handles all the parsing of the format string.
//	It is called when **src == '%'.
//	If the return value is negative, an error occurred.
//==============================================================================
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
		ftpf_read_one(&(fmt->conversion), src);
		return (1);
	}
	else
		return (ftpf_parse_fmt(fmt, src));
}
