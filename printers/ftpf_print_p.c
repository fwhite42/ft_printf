#include<stdint.h>

sizeof(uintptr_t) / sizeof(unsigned int)

void	ftpf_print_p(t_ftpf_fmt fmt, va_list args, int *counter)
{
	uintptr_t	ptr;

	ptr = va_arg(uintptr_t, args);
	ftpf_write_number_base("0123456789abcdef", 16)
}
