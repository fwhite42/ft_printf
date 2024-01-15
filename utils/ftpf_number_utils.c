/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_number_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:51:55 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 17:59:40 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_utils.h"

size_t	ftpf_write_number_base(char *base, unsigned int nbr, int *counter)
{
	unsigned char	digit;
	size_t			success;
	int				counter_initial_value;

	digit = nbr % baselen;
	counter_initial_value = *counter;
	if (digit != nbr)
		ftpf_write_number_base(base, nbr / baselen, counter);
	success = ftpf_write_one(counter, base[digit]);
	if (success < -1)
		return (success);
	return (*counter - (size_t) counter_initial_value);
}

void	ftpf_read_number(char **nbr)
{
	unsigned int	res;

	res = 0;
	while (ftpf_is_digit((**nbr)))
	{
		res *= 10;
		res += (unsigned int)(**nbr - '0');
		(*nbr)++;
	}
	return (res);
}
