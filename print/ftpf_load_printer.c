/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_load_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:37:51 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/19 13:48:29 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_printers.h"

t_ftpf_printer	ftpf_load_printer(char conversion_specifier)
{
	if (conversion_specifier == 'c')
		return (ftpf_print_c);
	else if (conversion_specifier == 'i' || conversion_specifier == 'd')
		return (ftpf_print_i);
	else if (conversion_specifier == 'p')
		return (ftpf_print_p);
	else if (conversion_specifier == 'x')
		return (ftf_print_x);
	else if (conversion_specifier == 'X')
		return (ftpf_print_X);
	else
		return (NULL);
}
