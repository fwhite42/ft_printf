/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   test_strings.c                                          4 2              */
/*                                                        (@)-=-(@)           */
/*   By: fwhite42 <FUCK THE NORM>                          (  o  )            */
/*                                                      _ /'-----'\_          */
/*   Created: 2024/01/25 02:30:32 by fwhite42          \\ \\     // //        */
/*   Updated: 2024/01/25 02:31:58 by fwhite42           _)/_\---/_\(_         */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<limits.h>
#include<stdio.h>

typedef int	(*t_printf)(const char *fmt, ...);

void	test(t_printf foo1, t_printf foo2, char *fmt, char *str)
{
	int	a;
	int	b;

	a = foo1(fmt, str);
	printf("\n");
	b = foo2(fmt, str);
	printf("\n");
	printf("a = %i		b = %i\n", a, b);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	test(ft_printf, printf, av[1], NULL);
	test(ft_printf, printf, av[1], av[2]);
	return (1);
}
