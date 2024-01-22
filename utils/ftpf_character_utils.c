/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_character_utils.c                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/15 18:01:48 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/22 12:29:37 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_constants.h"
#include<stdio.h>

static inline int	_ftpf_is_element_of(char *set, char x)
{
	while (*set)
	{
		if (*set == x)
			return (1);
		set++;
	}
	return (0);
}

int	ftpf_is_escape_char(char x)
{
	return (x == ESCAPE_CHARACTER);
}

int	ftpf_is_digit(char x)
{
	return (x >= '0' && x <= '9');
}

int	ftpf_is_flag(char x)
{
	return (_ftpf_is_element_of(FLAGS, x));
}

int	ftpf_is_conversion_specifier(char x)
{
	return (_ftpf_is_element_of(CONVERSION_SPECIFIERS, x));
}
