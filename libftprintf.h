/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   libftprintf.h                                           4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/02/17 10:39:37 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 11:29:12 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define FLAGS "#0 -+"
# define CONVERSION_SPECIFIERS "cspdiuxX%"
# define PRECISION_CHARACTER '.'
# define ESCAPE_CHARACTER '%'
# define NBR_BASE "0123456789"
# define HEX_BASE_LC "0123456789abcdef"
# define HEX_BASE_UC "0123456789ABCDEF"
# define FT_PRINTF_TARGET_FD 1
# include<stdarg.h>
# include<stdbool.h>

typedef struct s_ftpf_flag
{
	int	left_justify;
	int	force_sign;
	int	space_b4_int;
	int	zero_pad;
	int	alternate_form;
}	t_ftpf_flag;

typedef struct s_ftpf_fmt
{
	t_ftpf_flag	flag;
	int			field_width;
	int			precision;
	char		conversion;
}	t_ftpf_fmt;

typedef void(*t_ftpf_printer)(t_ftpf_fmt *fmt, va_list arg, int *counter);

t_ftpf_printer	ftpf_load_printer(char conversion_specifier);
int				ftpf_parse_flags(t_ftpf_fmt *dst, const char **src);
int				ftpf_parse_fmt(t_ftpf_fmt *fmt, const char **src);
void			ftpf_reset_format(t_ftpf_fmt *format);
void			ftpf_print_c(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_escape(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_i(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_s(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_p(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_u(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_x(t_ftpf_fmt *fmt, va_list ap, int *counter);
void			ftpf_print_x_uc(t_ftpf_fmt *fmt, va_list ap, int *counter);
bool			ftpf_is_escape_char(char x);
bool			ftpf_is_digit(char x);
bool			ftpf_is_flag(char x);
bool			ftpf_is_conversion_specifier(char x);
void			ftpf_write_one(int *counter, char c);
void			ftpf_write_many(int *counter, char c, int reps);
void			ftpf_write_string(int *counter, char *str, int limit);
int				ftpf_read_number(const char **source);
int				ftpf_write_number_base(char *base, unsigned int nbr, int *c);

#endif
