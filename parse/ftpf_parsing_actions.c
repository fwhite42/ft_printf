/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_parsing_actions.c                                  4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:11:18 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/24 15:14:27 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_structures.h"
#include"ft_printf_constants.h"
#include"ft_printf_utils.h"
//dev
#include<stdio.h>

int	ftpf_parse_flags(t_ftpf_fmt *format, const char **src)
{
	char	flag;

	ftpf_read_one(&flag, src);
	while (ftpf_is_flag(flag))
	{
		if (flag == '#')
			format->flag.alternate_form = 1;
		else if ((flag) == '-')
			format->flag.left_justify = 1;
		else if (flag == '+')
			format->flag.force_sign = 1;
		else if (flag == ' ')
			format->flag.space_b4_int = 1;
		else if (flag == '0')
			format->flag.zero_pad = 1;
		ftpf_read_one(&flag, src);
	}
	(*src)--;
	return (1);
}
