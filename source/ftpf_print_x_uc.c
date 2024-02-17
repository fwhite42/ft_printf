/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_x_uc.c                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/19 17:41:02 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 06:01:14 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_constants.h"
#include"ft_printf_structures.h"
#include"ft_printf_utils.h"
#include<stdarg.h>

static int	_compute_number_of_digits(unsigned int nbr);

static void	_compile_format(t_ftpf_fmt *fmt, unsigned int nbr, int length);

static void	_write_sign(t_ftpf_fmt *fmt, int *counter, unsigned int nbr);

static void	_write_number(t_ftpf_fmt *fmt, unsigned int nbr, int *counter);

void	ftpf_print_x_uc(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	int	nbr;
	int	length;

	nbr = va_arg(args, unsigned int);
	length = _compute_number_of_digits(nbr);
	_compile_format(fmt, nbr, length);
	if (fmt->field_width > 0 && !fmt->flag.left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
	_write_sign(fmt, counter, nbr);
	if (fmt->precision > 0)
		ftpf_write_many(counter, '0', fmt->precision);
	_write_number(fmt, nbr, counter);
	if (fmt->field_width > 0 && fmt->flag.left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
}

static int	_compute_number_of_digits(unsigned int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static void	_compile_format(t_ftpf_fmt *fmt, unsigned int nbr, int length)
{
	if (fmt->flag.force_sign)
		fmt->flag.force_sign = 0;
	if (fmt->precision > length)
	{
		fmt->precision -= length;
		length += fmt->precision;
	}
	else if (fmt->precision == 0 && nbr == 0)
	{
		fmt->flag.force_sign = 1;
		length = 0;
	}
	else if (fmt->precision != -1)
		fmt->precision = -2;
	if (fmt->flag.alternate_form && nbr)
		length += 2;
	if (fmt->field_width > length)
		fmt->field_width -= length;
	else
		fmt->field_width = -1;
	if (fmt->flag.zero_pad && fmt->precision == -1 && !fmt->flag.left_justify)
	{
		fmt->precision = fmt->field_width;
		fmt->field_width = -1;
	}
}

static void	_write_number(t_ftpf_fmt *fmt, unsigned int nbr, int *counter)
{
	if (nbr > 0)
	{
		ftpf_write_number_base(HEX_BASE_UC, nbr, counter);
		if (*counter == -1)
			return ;
	}
	else if (!fmt->flag.force_sign)
		ftpf_write_one(counter, '0');
}

static void	_write_sign(t_ftpf_fmt *fmt, int *counter, unsigned int nbr)
{
	if (fmt->flag.alternate_form && nbr != 0)
		ftpf_write_string(counter, "0X", 2);
}
