/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_read_write_utils.c                                 4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/22 10:03:39 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/22 11:01:33 by fwhite42           _)/_\---/_\(_         */
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

int	ftpf_write_string(int *counter, char *c, int limit)
{
	int	success;
	int	bytes_written;

	bytes_written = 0;
	while (*c && limit--)
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
