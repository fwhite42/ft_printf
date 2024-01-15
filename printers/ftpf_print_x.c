void ftpf_print_x(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	unsigned int data;

	data = va_arg(unsigned int, args);
	if (fmt.alternate_form)
		ftpf_write_string(counter, "0x");
	ftpf_write_number_base(counter, "0123456789abcdef", 16, data);
}
