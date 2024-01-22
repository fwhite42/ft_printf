/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_parse.c                                            4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/20 15:37:57 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/22 15:26:01 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parsers.h"
#include<stdio.h>

//==============================================================================
//	Handles all the parsing of the format string.
//	It is called when **src == '%'.
//	If the return value is negative, an error occurred.
//==============================================================================
int	ftpf_parse_fmt(t_ftpf_fmt *fmt, char **src)
{
	(*src)++;
	ftpf_parse_flags(fmt, src);
	ftpf_parse_field_width(fmt, src);
	ftpf_parse_precision(fmt, src);
	ftpf_read_one(&(fmt->conversion), src);
	while (!ftpf_is_conversion_specifier(fmt->conversion))
	{
		ftpf_read_one(&(fmt->conversion), src);
	}
	return (1);
}
