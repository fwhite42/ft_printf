/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   test_pointers.c                                         4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/25 02:13:57 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/25 02:24:52 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<limits.h>
#include<stdio.h>

typedef int	(*t_printf)(const char *fmt, ...);

void	test(t_printf f1, t_printf f2, char *fmt, unsigned long long nbr)
{
	int	a;
	int	b;

	a = f1(fmt, (void *)nbr);
	printf("\n");
	b = f2(fmt, (void *)nbr);
	printf("\n");
	printf("a = %i b = %i\n", a, b);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	test(ft_printf, printf, av[1], strtoull(av[2], NULL, 16));
	return (1);
}
