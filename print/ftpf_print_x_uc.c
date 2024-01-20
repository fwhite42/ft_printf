/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_x_uc.c                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/20 15:24:56 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/20 15:27:12 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_printers.h"

static inline int	_precompute_bytes_to_write(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr != nbr % 16)
	{
		i++;
		nbr = nbr % 16;
	}
	return (i);
}

void	ftpf_print_x(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	unsigned int	nbr;
	int				bytes_to_write;

	nbr = va_arg(args, unsigned int);
	bytes_to_write = _precompute_bytes_to_write(nbr);
	if (fmt->precision > bytes_to_write)
		bytes_to_write = fmt->precision;
	if ((fmt->flag).alternate_form)
		bytes_to_write += 2;
	if (fmt->field_width > bytes_to_write && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - bytes_to_write);
	if (fmt->flag.alternate_form)
		ftpf_write_string(counter, "0X", 2);
	if (fmt->precision > bytes_to_write)
	{
		if (fmt->flag.alternate_form)
			bytes_to_write -= 2;
		ftpf_write_many(counter, '0', fmt->precision - bytes_to_write);
	}
	ftpf_write_number_base(HEX_BASE_UC, nbr, counter);
	if (fmt->field_width > bytes_to_write && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - bytes_to_write);
}
