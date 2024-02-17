/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf_parsers.h                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 18:06:51 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/02/17 06:01:16 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSERS_H
# include"ft_printf_structures.h"

int	ftpf_parse_flags(t_ftpf_fmt *dst, const char **src);
int	ftpf_parse_fmt(t_ftpf_fmt *fmt, const char **src);
#endif
