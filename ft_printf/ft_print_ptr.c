/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:02:16 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/24 15:52:08 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int			r;
	int			count;
	uintptr_t	p;

	p = (uintptr_t) ptr;
	r = 0;
	count = 0;
	if (ptr == NULL)
		return (ft_printstr("(nil)"));
	r = ft_printstr("0x");
	if (r == -1)
		return (-1);
	count += 2;
	r = ft_print_ptr_help(p, &count);
	if (r == -1)
		return (-1);
	return (count);
}

int	ft_print_ptr_help(uintptr_t n, int *count)
{
	char	*hex;
	int		r;

	hex = "0123456789abcdef";
	r = 0;
	if (n < 16)
	{
		r = write(1, &hex[n], 1);
		(*count)++;
		if (r != 1)
			return (-1);
	}
	else
	{
		r = ft_print_ptr_help(n / 16, count);
		if (r == -1)
			return (-1);
		r = ft_print_ptr_help(n % 16, count);
		if (r == -1)
			return (-1);
	}
	return (0);
}
