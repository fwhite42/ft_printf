/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   test_unsigned_hex.c                                     4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/25 02:27:50 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/25 11:45:56 by fcandia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<limits.h>
#include<stdio.h>

typedef int	(*t_printf)(const char *fmt, ...);

void	test(t_printf f1, t_printf f2, char *fmt, unsigned int nbr)
{
	int	a;
	int	b;

	a = f1(fmt, nbr);
	printf("\n");
	b = f2(fmt, nbr);
	printf("\n");
	printf("a = %i b = %i\n", a, b);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	test(ft_printf, printf, av[1], (unsigned int)strtoul(av[2], NULL, 10));
	return (1);
}
