/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:24:07 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/20 12:30:36 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTERS_H
# define FT_PRINTF_PRINTERS_H
# include"ft_printf_structures.h"
# include"ft_printf_constants.h"
# include"ft_printf_utils.h"
# include<stdarg.h>
# include<stdint.h>

typedef void(	*t_ftpf_printer)(t_ftpf_fmt fmt, va_list arg, int *counter);
t_ftpf_printer	ftpf_load_printer(char conversion_specifier);

void			ftpf_print_c(t_ftpf_fmt *format, va_list args, int *counter);
void			ftpf_print_i(t_ftpf_fmt *format, va_list args, int *counter);
void			ftpf_print_s(t_ftpf_fmt *format, va_list args, int *counter);
void			ftpf_print_p(t_ftpf_fmt *format, va_list args, int *counter);
void			ftpf_print_x(t_ftpf_fmt *format, va_list args, int *counter);
void			ftpf_print_X(t_ftpf_fmt *format, va_list args, int *counter);
#endif
