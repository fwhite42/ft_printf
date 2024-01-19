/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_read_write_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:15:46 by fwhite42          #+#    #+#             */
/*   Updated: 2024/01/18 20:58:14 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_utils.h"

int	ftpf_write_one(int *counter, char c)
{
	int	success;

	success = write(1, &c, 1);
	if (success > 0)
		*counter += 1;
	return (success);
}

int	ftpf_write_many(int *counter, char c, int reps)
{
	int	success;

	success = 1;
	while (reps-- && success)
		success = ftpf_write_one(counter, c);
	return (reps);
}

int	ftpf_write_string(int *counter, char *c)
{
	int	success;
	int	bytes_written;

	bytes_written = 0;
	while (*c)
	{
		success = ftpf_write_one(counter, *c);
		if (success < 0)
			return (success);
		bytes_written += success;
		c++;
	}
	return (bytes_written);
}

bool	ftpf_read_one(char *destination, char **source)
{
	if (destination == NULL || source == NULL || *source == NULL)
		return (false);
	*destination = **source;
	(*source)++;
	return (true);
}

bool	ftpf_read_many(char *destination, char **source, int bytes_to_consume)
{
	while (bytes_to_consume--)
	{
		if (!ftpf_read_one(destination, source))
			return (false);
	}
	return (true);
}
