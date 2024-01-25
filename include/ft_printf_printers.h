/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf_printers.h                                    4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/19 11:24:07 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/25 12:31:59 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTERS_H
# define FT_PRINTF_PRINTERS_H
# include"ft_printf_structures.h"
# include"ft_printf_constants.h"
# include"ft_printf_utils.h"
# include<stdarg.h>
# include<stdint.h>

typedef void(*t_ftpf_printer)(t_ftpf_fmt *fmt, va_list arg, int *counter);
t_ftpf_printer	ftpf_load_printer(char conversion_specifier);

void			ftpf_print_c(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_escape(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_i(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_s(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_p(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_u(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_x(t_ftpf_fmt *format, va_list ap, int *counter);
void			ftpf_print_x_uc(t_ftpf_fmt *format, va_list ap, int *counter);
#endif
