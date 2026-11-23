/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:59:19 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/23 15:59:57 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	r;
	size_t	count;

	r = 0;
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			r = ft_process(args, *(str + 1));
			if (r == -1)
			{
				va_end(args);
				return (-1);
			}
			count += r;
			str += 2;
		}
		else
		{
			r = ft_printchar(*str);
			if (r == -1)
			{
				va_end(args);
				return (-1);
			}
			count += r;
			str++;
		}
	}
	va_end(args);
	return ((int)count);
}

int	ft_process(va_list args, char c)
{
	size_t	r;

	r = 0;
	if (c == 'c')
		r = ft_printchar(va_arg(args, int));
	else if (c == 's')
		r = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		r = ft_print_ptr(va_arg(args, void *));
	else if (c == 'd')
		r = ft_print_number(va_arg(args, int));
	else if (c == 'u')
		r = ft_print_u_number(va_arg(args, unsigned int));
	else if (c == 'i')
		r = ft_print_number(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		r = ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		r = ft_printpercent();
	return (r);
}
