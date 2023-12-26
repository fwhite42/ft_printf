/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwhite42 <FUCK THE NORM>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:03:22 by fwhite42          #+#    #+#             */
/*   Updated: 2023/12/26 10:37:35 by fwhite42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdarg.h>

int	ft_printf(char *src, ...)
{
	va_list	args;

	va_start(args, src);
	while (*src)
	{
		if (*src != '%')
			write(1, *(src++), 1);
		else if (src[0] == '%' && src[1] != 0)
		{
			ft_get_printer(src[1], *ft_print);
			ft_print(args);
		}
	}
}

//TO DO, replace char id with char *idsrc
void ft_get_printer(char id, (int (*print)(*va_list)))
{
	if (id == 'c')
	else if (id == 's')
	else if	(id == 'p')
	else if	(id == 'd')
	else if	(id == 'i')
	else if	(id == 'x')
	else if (id == 'X')
	else if (id == '%')
}


int ft_print_char(va_list *args)
{
	char c;
	c = va_arg(*args, char);
	ft_putchar_fd(1, c);
}

int ft_print_string(va_list *args)
{
	char *str;

	str = va_arg(arg, char *);
	ft_putstr_fd(1, str);
}

int ft_print_number_base(va_list *args, char *base)
{
	int  n;
	
	n = va_arg(args, i);
	ft_putnbr_fd_base(1, base);
}
