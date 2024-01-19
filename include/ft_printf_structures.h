/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structures.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:09:43 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/18 21:00:54 by fwhite42         ###   ########.fr       */
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
