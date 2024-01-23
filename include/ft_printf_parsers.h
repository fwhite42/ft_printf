/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf_parsers.h                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/20 15:39:08 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/23 11:52:54 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSERS_H
# include"ft_printf_structures.h"
# include"ft_printf_utils.h"
# include"stdarg.h"
//==============================================================================
//	> File
//		ftpf_parsing_actions.c
//	> Description
//		Handles the parsing of different chunks of a format string (indiviually)
//==============================================================================
int	ftpf_parse_flags(t_ftpf_fmt *dst, const char **src);
int	ftpf_parse_field_width(t_ftpf_fmt *dst, const char **src);
int	ftpf_parse_precision(t_ftpf_fmt *dst, const char **src);
//==============================================================================
//	> File
//		ftpf_parse.c
//	> Description
//		Handles the whole parsing of the format-string
//==============================================================================
int	ftpf_parse_fmt(t_ftpf_fmt *fmt, const char **src);
#endif
