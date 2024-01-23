/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_number_utils.c                                     4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:51:55 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/23 11:15:02 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_utils.h"

static int	_ftpf_write_number_base(char *b, size_t bl, unsigned int n, int *i)
{
	unsigned char	digit;
	int				t;
	int				success;

	digit = n % bl;
	t = *i;
	if (digit != n)
		_ftpf_write_number_base(b, bl, n / bl, i);
	success = ftpf_write_one(i, b[digit]);
	if (success < 0)
		return (success);
	return (*i - t);
}

int	ftpf_write_number_base(char *base, unsigned int nbr, int *counter)
{
	int				baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	return (_ftpf_write_number_base(base, baselen, nbr, counter));
}

int	ftpf_read_number(const char **nbr)
{
	int	res;

	if (nbr == NULL || *nbr == NULL || !ftpf_is_digit(**nbr))
		return (-1);
	res = 0;
	while (ftpf_is_digit((**nbr)))
	{
		res *= 10;
		res += (**nbr - '0');
		(*nbr)++;
	}
	return (res);
}
