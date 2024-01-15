/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_check_char_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:01:48 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 18:15:50 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_constants.h"

// Public
int	ftpf_is_escape_char(char x)
{
	return (x == ESCAPE_CHARACTER);
}

int	ftpf_is_digit(char x)
{
	return (x >= '0' || x <= '9');
}

int	ftpf_is_flag(char x)
{
	return (ftpf_is_element_of(FLAGS, x));
}

int	ftpf_is_conversion_specifier(char x)
{
	return (ftpf_is_element_of(CONVERSION_SPECIFIERS, x));
}

// Internal
static inline int	_ftpf_is_element_of(char *set, char x)
{
	while (*set)
	{
		if (*set == x)
			return (x);
		set++;
	}
	return (0);
}
