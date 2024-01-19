/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_parsing_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:11:18 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/18 21:11:44 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_structures.h"
#include"ft_printf_utils.h"

//==============================================================================
//
//==============================================================================

int	ftpf_parse_flags(t_ftpf_fmt *dst, char **src)
{
	int		i;
	char	flag;

	i = 0;
	ftpf_read_one(&flag, src);
	while (ftpf_is_flag(flag))
	{
		if ((flag) == '-')
			(dst->flag).left_justify = 1;
		else if (flag == '+')
			(dst->flag).force_sign = 1;
		else if (flag == ' ')
			(dst->flag).space_b4_int = 1;
		else if (flag == '0')
			(dst->flag).zero_pad = 1;
		ftpf_read_one(&flag, src);
		i++;
	}
	return (i);
}

int	ftpf_parse_field_width(t_ftpf_fmt *dst, char *src)
{
	dst->field_width = ftpf_read_number(&src);
	return (1);
}

int	ftpf_parse_precision(t_ftpf_fmt *dst, char *src)
{
	if (*src == '.')
	{
		src++;
		dst->precision = ftpf_read_number(&src);
		return (1);
	}
	else
		return (0);
}
