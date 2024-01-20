/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_parse.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/20 15:37:57 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/20 15:38:39 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"

//==============================================================================
//	Handles all the parsing of the format string.
//	It is called when **src == '%'.
//	If the return value is negative, an error occurred.
//==============================================================================
int	ftpf_parse_fmt(t_ftpf_fmt *fmt, char **src)
{
	int	success;

	success = ftpf_parse_flags(fmt, src);
	if (
		ftpf_parse_flags(fmt, src) \
		&& ftpf_parse_field_width(fmt, src) \
	)
		return (ftpf_parse_precision(fmt, src));
	else
		return (-1);
}
