void	ftpf_print_uint(t_ftpf_fmt *fmt, va_list args, int *counter, char *base)
{
	int nbr;
	int	bytes_printed;

	nbr = va_arg(unsigned int, args);
	bytes_printed = ftpf_print_nbr_base(nbr, base);
	*counter += bytes_printed;
}
