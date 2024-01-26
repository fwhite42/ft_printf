/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_any.c                                        4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 03:02:38 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 03:58:43 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
if (fmt->field_width > 0 && !fmt->flag.left_justify)
	ftpf_write_many(counter, ' ', fmt->field_width)

ftpf_print_decorator(counter, number, base);
if (fmt->precision > 0)
	ftpf_write_many(counter, '0', fmt->precision);
if  (fmt)
ftpf_print_number(counter, number, base);
if(fmt->field_width > 0 && fmt->flag.left_justify)
	ftpf_write_many(counter, ' ', fmt-field_width)
