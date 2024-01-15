/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:18:37 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/15 19:19:10 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ftpf_print_uint(t_ftpf_fmt *fmt, va_list args, int *counter, char *base)
{
	int nbr;
	int	bytes_printed;

	nbr = va_arg(unsigned int, args);
	bytes_printed = ftpf_print_nbr_base(nbr, base);
	*counter += bytes_printed;
}
