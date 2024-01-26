/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_i.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/19 17:41:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 04:36:23 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"
#include"ft_printf_constants.h"
#include<limits.h>
#include<stdio.h>

static int	_compute_number_of_digits(int nbr);

static void	_compile_format(t_ftpf_fmt *fmt, int nbr, int length);

static void	_write_sign(t_ftpf_fmt *fmt, int nbr, int *counter);

static void	_write_number(t_ftpf_fmt *fmt, int nbr, int *counter);

void	ftpf_print_i(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	int		nbr;
	int		length;

	nbr = va_arg(args, int);
	length = _compute_number_of_digits(nbr);
	_compile_format(fmt, nbr, length);
	if (fmt->field_width > 0 && !fmt->flag.left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
	_write_sign(fmt, nbr, counter);
	if (fmt->precision > 0)
		ftpf_write_many(counter, '0', fmt->precision);
	_write_number(fmt, nbr, counter);
	if (fmt->field_width > 0 && fmt->flag.left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
}

static int	_compute_number_of_digits(int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	_compile_format(t_ftpf_fmt *fmt, int nbr, int length)
{
	if (fmt->flag.alternate_form)
		fmt->flag.alternate_form = 0;
	if (fmt->precision > length)
	{
		fmt->precision -= length;
		length += fmt->precision;
	}
	else if (fmt->precision == 0 && nbr == 0)
	{
		fmt->flag.alternate_form = 1;
		length = 0;
	}
	else if (fmt->precision != -1)
		fmt->precision = -2;
	if (fmt->field_width > length)
		fmt->field_width -= length;
	else
		fmt->field_width = -1;
	if (nbr < 0 || fmt->flag.force_sign || fmt->flag.space_b4_int)
		fmt->field_width--;
	if (fmt->flag.zero_pad && fmt->precision == -1 && !fmt->flag.left_justify)
	{
		fmt->precision = fmt->field_width;
		fmt->field_width = -1;
	}
}

static void	_write_number(t_ftpf_fmt *fmt, int nbr, int *counter)
{
	int		quotient;
	int		digit;

	if (nbr > 0)
		ftpf_write_number_base(NBR_BASE, (unsigned int) nbr, counter);
	else if (nbr < 0)
	{
		if (nbr / 10)
		{
			quotient = (unsigned int) -(nbr / 10);
			digit = (unsigned int) -(nbr + 10) % 10;
			ftpf_write_number_base(NBR_BASE, quotient, counter);
			ftpf_write_number_base(NBR_BASE, digit, counter);
		}
		else
			ftpf_write_number_base(NBR_BASE, (unsigned int) -nbr, counter);
	}
	else if (!fmt->flag.alternate_form)
		ftpf_write_one(counter, '0');
}

static void	_write_sign(t_ftpf_fmt *fmt, int nbr, int *counter)
{
	if (nbr < 0)
		ftpf_write_one(counter, '-');
	else if (fmt->flag.force_sign)
		ftpf_write_one(counter, '+');
	else if ((fmt->flag).space_b4_int)
		ftpf_write_one(counter, ' ');
}
