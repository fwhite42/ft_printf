/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_parsing_actions.c                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/15 22:11:18 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 18:10:38 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_structures.h"
#include"ft_printf_constants.h"
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
