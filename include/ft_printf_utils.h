/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:24:54 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 18:28:28 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
//=============================================================================
//	> File
//		ftpf_character_utils.c
//	> Description
//		Utils to check if a character has a special role in format strings
//=============================================================================
int		ftpf_is_escape_char(char c);
int		ftpf_is_digit(char x);
int		ftpf_is_flag(char x);
int		ftpf_is_conversion_specifier(char x);
//=============================================================================
//	> File
//		ftpf_read_write_utils.c
// 	> Description
// 		Utils to write into the standard input
//		Utils to consume data from a string:
//=============================================================================
int		ftpf_write_one(int *counter, char c);
int		ftpf_write_string(int *counter, char *str);
int		ftpf_read_one(char *dst, char **src);
int		ftpf_read_many(char *dst, char **src, int bytes_to_consume);
//=============================================================================
//	> File
//		ftpf_read_write_utils.c
// 	> Description
//		Atoi and Itoa analogs:
//=============================================================================
int		ftpf_read_number(char *nbr);
int		ftpf_write_number_base(char *base, int nbr);
#endif
