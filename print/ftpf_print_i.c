/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_i.c                                          ???              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/19 17:41:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/19 17:42:31 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"
#include"ft_printf_constants.h"
#include<limits.h>

static inline int	nbr_len(int nbr)
{
	int	i;

	if (nbr < 0)
		i = 1;
	else
		i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
		if (!nbr)
			i++;
	}
	return (i);
}

void	ftpf_print_i(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	int		nbr;
	char	digit;

	nbr = va_arg(args, int);
	if (nbr_len(nbr) < 1)
		return ;
	if (nbr < 0)
	{
		ftpf_write_one(counter, '-');
		ftpf_write_number_base(NBR_BASE, (unsigned int) -(nbr / 10), counter);
		digit = (nbr + 10) % 10;
		ftpf_write_number_base(NBR_BASE, (unsigned int) digit, counter);
	}
	else
	{
		if ((fmt->flag).force_sign)
			ftpf_write_one(counter, '+');
		ftpf_write_number_base(NBR_BASE, (unsigned int) nbr, counter);
	}
}
