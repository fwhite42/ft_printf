/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_print_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:56:30 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/19 16:38:16 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	_precompute_bytes_to_be_written(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	ftpf_print_s(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	char	*str;
	int		bytes_to_be_written;

	str = va_list(args, char *);
	if (fmt->precision < bytes_to_be_written)
		bytes_to_be_written = fmt->precision;
	ftpf_write_string(str, bytes_to_be_writtten);
}
