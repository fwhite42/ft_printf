/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_i.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/19 17:41:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/23 19:07:41 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"
#include"ft_printf_constants.h"
#include<limits.h>
#include<stdio.h>

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

static inline void	_handle_positive(t_ftpf_fmt *fmt, int nbr, int *counter)
{
	if ((fmt->flag).force_sign)
		ftpf_write_one(counter, '+');
	ftpf_write_number_base(NBR_BASE, (unsigned int) nbr, counter);
}

static inline void	_handle_negative(t_ftpf_fmt *fmt, int nbr, int *counter)
{
	int		a;
	int		b;

	ftpf_write_one(counter, '-');
	if (nbr / 10)
	{
		a = (unsigned int) -(nbr / 10);
		b = (unsigned int) -(nbr + 10) % 10;
		ftpf_write_number_base(NBR_BASE, a, counter);
		ftpf_write_number_base(NBR_BASE, b, counter);
	}
	else
		ftpf_write_number_base(NBR_BASE, (unsigned int) -nbr, counter);
}

void	ftpf_print_i(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	int		nbr;

	nbr = va_arg(args, int);
	if (nbr_len(nbr) < 1)
		return ;
	if (nbr < 0)
		_handle_negative(fmt, nbr, counter);
	else
		_handle_positive(fmt, nbr, counter);
}
