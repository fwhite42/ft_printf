/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_print_escape.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 17:56:50 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 11:18:54 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include"libftprintf.h"

void	ftpf_print_escape(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	(void) args;
	if (fmt->field_width > -1 && !(fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
	ftpf_write_one(counter, '%');
	if (fmt->field_width > -1 && (fmt->flag).left_justify)
		ftpf_write_many(counter, ' ', fmt->field_width - 1);
}
