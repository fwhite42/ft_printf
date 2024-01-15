/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_write_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:15:46 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/14 18:42:59 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ftpf_write_one(int *counter, char c)
{
	size_t success;

	success = write(1, &c, 1);
	if (s > 0)
		*counter += 1;
	return success;
}

size_t	ftpf_write_string(int *counter, char *c)
{
	size_t success;
	size_t bytes_written;
	
	while (*c)
	{
		success = ftpf_write_one(counter, *c);
		if (success < 0)
			return (success);
		bytes_written += success;
		c++;
	}
	return (bytes_written)
}

void	ftpf_read_one(char **str, char *slot)
{
	*slot = **str;
	(*str)++;
}

void	ftpf_consume_string(char **str, int bytes_to_consume)
{
	*str += bytes_to_consume;
}
