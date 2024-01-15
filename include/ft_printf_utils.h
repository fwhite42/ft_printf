/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:24:54 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 00:48:05 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_UTILS
# define FT_PRINTF_UTILS_H
// Utils to write into the standard in:
int	ftpf_write_one(int *counter, char c);
int	ftpf_write_string(int *counter, char *str);
// Utils to consume data from a string:
void	ftpf_read_one(char *dst, char **src);
void	ftpf_read_many(char *dst, char **src, int bytes_to_consume);
// Parsers for printf format string:
void	ftpf_parse_flags(t_ftpf_fmt *dst, char **src);
void	ftpf_parse_field_width(t_ftpf_fmt *dst, char **src);
void	ftpf_parse_precision(t_ftpf_fmt *dst, char **src);
void	ftpf_parse_conversion_specifier(t_ftpf_fmt *dst, char **src);
void	ftpf_parse_all(t_ftpf_fmt *dst, char **src);
// Atoi and Itoa analogs:
void	ftpf_read_number(char *nbr);
void	ftpf_write_number_base(char *base, int nbr);
#endif
