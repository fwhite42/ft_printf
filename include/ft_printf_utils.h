/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:01:24 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/18 02:08:34 by fwhite42         ###   ########.fr       */
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
int		ftpf_is_escape_char(char x);
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
size_t	ftpf_write_one(int *counter, char c);
size_t	ftpf_write_many(int *counter, char c, size_t reps);
size_t	ftpf_write_string(int *counter, char *str);
size_t	ftpf_read_one(char *destination, char **src);
size_t	ftpf_read_many(char *destination, char **src, size_t reps);

//=============================================================================
//	> File
//		ftpf_read_write_utils.c
// 	> Description
//		Atoi and Itoa analogs:
//=============================================================================
int		ftpf_read_number_base(char *base, int base_length, char *nbr);
int		ftpf_write_number_base(char *base, int base_length, int nbr);
int		ftpf_check_base(char *base);
#endif
