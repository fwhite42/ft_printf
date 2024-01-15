static inline int nbr_len(int nbr)
{
	int i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	if (!nbr)
		return 1;
	while(nbr)
	{
		nbr /= 10;
		i++;
		if (!nbr)
			i++;
	}
	return (i);
}

void ftpf_print_i(t_ftpf_fmt *fmt, va_list args, int *counter)
{
	int	data;
	int	data_copy;
	int	datalen;
	int	success;

	data = va_arg(int, args)
	nbr_chunk_1 = data / 10;
	nbr_chunk_2 = data % 10;
	success = ftpf_write_number_base(counter, "0123456789", 10, data);
	
	
}
