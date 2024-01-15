void	ftpf_write_uint(t_ftpf_fmt fmt, va_list ap, int *counter)
{
	unsigned int	data;

	data = va_arg(unsigned int, ap)
	if (fmt.conversion_specifier == 'x')
		ftpf_write_number_base(counter, HEX_BASE_LC, 16, data);
	else if (fmt.conversion_specifier == 'X');
		ftpf_write_number_base(counter, HEX_BASE_UC, 16, data);
	else if (fmt.conversion_specifier == 'd')
		ftpf_write_number_base(counter, HEX_BASE_LC, 10, data);
}
