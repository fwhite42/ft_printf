/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:38:33 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/19 10:56:50 by fwhite42         ###   ########.fr       */
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
int	ftpf_parse_flags(t_ftpf_fmt *dst, char **src);
int	ftpf_parse_field_width(t_ftpf_fmt *dst, char **src);
int	ftpf_parse_precision(t_ftpf_fmt *dst, char **src);
//==============================================================================
//	> File
//		ftpf_parse.c
//	> Description
//		Handles the whole parsing of the format-string
//==============================================================================
int	ftpf_parse_fmt(t_ftpf_fmt *fmt, char **src);
#endif
