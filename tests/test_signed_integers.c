#include"ft_printf.h"
#include<limits.h>
#include<stdio.h>

typedef int (*printf_like)(const char *fmt, ...);

void test(printf_like foo1, printf_like foo2, char *fmt, int nbr)
{
	int a;
	int b;

	a = foo1(fmt, nbr);
	printf("\n");
	b = foo2(fmt, nbr);
	printf("\n");
	printf("a = %i		b = %i\n", a, b);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	test(ft_printf, printf, av[1], atoi(av[2]));
	return (1);
}
