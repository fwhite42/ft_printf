#include"ft_printf.h"

int main()
{
	char *str;
	int	i;

	str = "Hello World";
	i = 14728;

	ft_printf("%c\n", str[1]);
	ft_printf("%s\n", str);
	ft_printf("%i\n", i);
	ft_printf("%d\n", i);
	ft_printf("%x\n", i);
	return (0);
}
