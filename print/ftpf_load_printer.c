/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_load_printer.c                                     4 2              */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:37:51 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/22 13:56:17 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_printers.h"

t_ftpf_printer	ftpf_load_printer(char conversion_specifier)
{
	if (conversion_specifier == 'c')
		return (ftpf_print_c);
	else if (conversion_specifier == 's')
		return (ftpf_print_s);
	else if (conversion_specifier == 'i' || conversion_specifier == 'd')
		return (ftpf_print_i);
	else if (conversion_specifier == 'p')
		return (ftpf_print_p);
	else if (conversion_specifier == 'x')
		return (ftpf_print_x);
	else if (conversion_specifier == 'X')
		return (ftpf_print_x_uc);
	else
		return (NULL);
}
