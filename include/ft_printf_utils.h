/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:01:24 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/19 16:38:17 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include<stdlib.h>
# include<stdbool.h>
# include<unistd.h>
//=============================================================================
//	> File
//		ftpf_character_utils.c
//	> Description
//		Utils to check if a character has a special role in format strings
//=============================================================================
bool	ftpf_is_escape_char(char x);
bool	ftpf_is_digit(char x);
bool	ftpf_is_flag(char x);
bool	ftpf_is_conversion_specifier(char x);

//=============================================================================
//	> File
//		ftpf_read_write_utils.c
// 	> Description
// 		Utils to write into the standard input
//		Utils to consume data from a string:
//=============================================================================
int		ftpf_write_one(int *counter, char c);
int		ftpf_write_many(int *counter, char c, int reps);
int		ftpf_write_string(int *counter, char *str);
bool	ftpf_read_one(char *destination, char **src);
bool	ftpf_read_many(char *destination, char **src, int reps);

//=============================================================================
//	> File
//		ftpf_read_write_utils.c
// 	> Description
//		Atoi and Itoa analogs:
//=============================================================================
int		ftpf_verify_base_and_get_base_length(char *base);
int		ftpf_read_number(char **source);
int		ftpf_write_number_base(char *base, unsigned int nbr, int *counter);
#endif
