/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_fmt_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:25:04 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/14 21:29:21 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_structures.h"
#include"ft_printf_read_write_utils.h"

int	ftpf_parse_flags(t_ftpf_flag *dst, char **src)
{
	int i;
	char flag;

	i = 0;
	ftpf_read_one(src, &flag);
	while(ftpf_is_flag(flag))
	{
		if ((flag) == '-')
			(dst->flag).left_justify = 1;
		else if (flag == '+')
			(dst->flag).force_sign = 1;
		else if (flag == ' ')
			(dst->flag).space_b4_int = 1;
		else if (flag == '0')
			(dst->flag).zero_pad = 1;
		ftpf_read_one(src, &flag);
		i++;
	}
	return (i);
}

int	ftpf_parse_field_width(t_ftpf_fmt *dst, char *src)
{
	return (ftpf_read_number_base("0123456789", &(dst->field_width), src));
}

int	ftpf_parse_precision(t_ftpf_fmt *dst, char *src)
{
	if (*src == '.')
	{
		ftpf_consume_string(char *src, 1);
		return (ftpf_atoi(&(dst->precision), src + 1));
	}
	else
		return (0);
}
