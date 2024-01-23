#include"ft_printf.h"
#include<limits.h>
#include<stdio.h>

int main()
{
	int	i;
	int a;
	int b;
	
	i = -24543;

	ft_printf("%p\n", (void *)LONG_MIN);
	printf("%p\n", (void *)LONG_MIN);

	printf("%i\n", -92);
	ft_printf("%i\n", -92);

	ft_printf("%d\n", i);
	printf("%d\n", i);

	ft_printf("%x\n", i);
	printf("%x\n", i);

	ft_printf("%u\n", 1011);
	printf("%u\n", 1011);

	ft_printf("%#x\n", i);
	printf("%#x\n", i);

	ft_printf("%X\n", i);
	printf("%X\n", i);

	ft_printf("%#X\n", i);
	printf("%#X\n", i);

	ft_printf("%p\n", &i);
	printf("%p\n", &i);

	a = ft_printf("%p\n", "");
	b = printf("%p\n", "");
	ft_printf("%i %i\n", a, b);
	return (0);
}
