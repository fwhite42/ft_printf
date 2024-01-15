#include"ft_printf_parser_utils.h"

int	ftpf_parse_fmt(t_ftpf_fmt *fmt, char **src)
{
	int bytes_read;

	ftpf_parse_flags(fmt, src);
	ftpf_parse_field_width(fmt, src);
	ftpf_parse_precision(fmt, src);
}
