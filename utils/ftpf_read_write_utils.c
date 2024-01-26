/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftpf_read_write_utils.c                                 4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                       _/'-----'\_          */
/*   Created: 2024/01/22 10:03:39 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/26 04:26:44 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf_utils.h"

void	ftpf_write_one(int *counter, char c)
{
	if (*counter == -1)
		return ;
	else if (write(1, &c, 1) < 0)
		*counter = -1;
	else
		*counter += 1;
}

void	ftpf_write_many(int *counter, char c, int reps)
{
	while (reps-- && *counter != -1)
		ftpf_write_one(counter, c);
}

void	ftpf_write_string(int *counter, char *c, int limit)
{
	while (*c && limit-- && *counter != -1)
		ftpf_write_one(counter, *(c++));
}

void	ftpf_read_one(char *destination, const char **source)
{
	if (destination == NULL || source == NULL || *source == NULL)
		return ;
	*destination = **source;
	(*source)++;
}
