/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_character_utils.c                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/15 18:01:48 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 11:18:53 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

static inline bool	_ftpf_is_element_of(char *set, char x)
{
	while (*set)
	{
		if (*set == x)
			return (true);
		set++;
	}
	return (false);
}

bool	ftpf_is_escape_char(char x)
{
	return (x == ESCAPE_CHARACTER);
}

bool	ftpf_is_digit(char x)
{
	return (x >= '0' && x <= '9');
}

bool	ftpf_is_flag(char x)
{
	return (_ftpf_is_element_of(FLAGS, x));
}

bool	ftpf_is_conversion_specifier(char x)
{
	return (_ftpf_is_element_of(CONVERSION_SPECIFIERS, x));
}
