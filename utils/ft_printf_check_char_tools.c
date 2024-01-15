#include"ft_printf_constants.h"

int	ftpf_is_escape_char(char x)
{
	return x == ESCAPE;
}

int	ftpf_is_element_of(char *set, char x)
{
	while (*set)
	{
		if (*set == x)
			return (x);
	}
	return (0);
}

int	ftpf_is_digit(char x)
{
	ftpf_is_element_of("0123456789", x);
}

int	ftpf_is_flag(char x)
{
	return ftpf_is_element_of(PRINTF_FLAGS, x);
}

int	ftpf_is_conversion_specifier(char x)
{
	return ftpf_is_element_of(PRINTF_CONVERSION_SPECIFIERS, x);
}
