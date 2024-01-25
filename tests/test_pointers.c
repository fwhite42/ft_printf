#include"ft_printf.h"
#include<limits.h>
#include<stdio.h>

typedef int (*printf_like)(const char *fmt, ...);

void test(printf_like my_printf, printf_like orig_printf, char *fmt, unsigned long long nbr)
{
	int a;
	int b;

	a = my_printf(fmt, (void *)nbr);
	printf("\n");
	b = orig_printf(fmt, (void *)nbr);
	printf("\n");
	printf("a = %i b = %i\n", a, b);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	test(ft_printf, printf, av[1], strtoull(av[2], NULL, 16));
	return (1);
}
