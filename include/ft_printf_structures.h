/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf_structures.h                                  4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/26 12:23:24 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 18:07:56 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTURES_H
# define FT_PRINTF_STRUCTURES_H

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
#endif
