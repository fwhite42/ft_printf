/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_p.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 17:58:13 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 11:37:45 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */
#include<stdint.h>
#include<stdarg.h>
#include"libftprintf.h"

static void	_print_pointer(uintptr_t nbr, int *counter)
{
	if ((nbr >> 8))
	{
		_print_pointer(nbr >> 8, counter);
		if (nbr % 256 < 16)
			ftpf_write_one(counter, '0');
	}
	ftpf_write_number_base(HEX_BASE_LC, (unsigned int)(nbr % 256), counter);
}

static int	_compute_length(uintptr_t nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 16;
		++i;
	}
	return (i);
}

static void	_compile_flags(t_ftpf_fmt *fmt, uintptr_t nbr)
{
	int	length;

	length = _compute_length(nbr);
	fmt->precision -= length;
	if (fmt->precision > 0)
		length = fmt->precision;
	fmt->field_width -= (2 + length);
}

void	ftpf_print_p(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	uintptr_t	ptr;

	if (*counter == -1)
		return ;
	ptr = va_arg(args, uintptr_t);
	_compile_flags(fmt, ptr);
	if (fmt->field_width > 0 && !fmt->flag.left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
	if (*counter == -1)
		return ;
	ftpf_write_string(counter, "0x", 2);
	if (*counter == -1)
		return ;
	if (fmt->precision > 0)
		ftpf_write_many(counter, '0', fmt->precision);
	if (*counter == -1)
		return ;
	_print_pointer(ptr, counter);
	if (fmt->field_width > 0 && fmt->flag.left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width);
	if (*counter == -1)
		return ;
}
