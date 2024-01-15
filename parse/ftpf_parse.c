/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_fmt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:45:44 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 17:51:14 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_parser_utils.h"

//==============================================================================
//	Handles all the parsing of the format string.
//	It is called when **src == '%'.
//	If the return value is negative, an error occurred.
//==============================================================================
int	ftpf_parse_fmt(t_ftpf_fmt *fmt, char **src)
{
	int	bytes_read;

	ftpf_parse_flags(fmt, src);
	ftpf_parse_field_width(fmt, src);
	ftpf_parse_precision(fmt, src);
}
