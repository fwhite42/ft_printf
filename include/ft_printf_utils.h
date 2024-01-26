/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf_utils.h                                       4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 18:06:25 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 18:06:30 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include<stdlib.h>
# include<stdbool.h>
# include<unistd.h>

bool	ftpf_is_escape_char(char x);
bool	ftpf_is_digit(char x);
bool	ftpf_is_flag(char x);
bool	ftpf_is_conversion_specifier(char x);

void	ftpf_write_one(int *counter, char c);
void	ftpf_write_many(int *counter, char c, int reps);
void	ftpf_write_string(int *counter, char *str, int limit);

int		ftpf_read_number(const char **source);
int		ftpf_write_number_base(char *base, unsigned int nbr, int *counter);
#endif
