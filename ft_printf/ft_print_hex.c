/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:58:43 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/23 15:58:52 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int x)
{
	int	count;
	int	r;

	r = 0;
	count = 0;
	r = ft_print_hex_help(n, x, &count);
	if (r == -1)
		return (-1);
	return (count);
}

int	ft_print_hex_help(unsigned int n, int x, int *count)
{
	char	*hex;
	char	*hex_u;
	int		r;

	*hex = "0123456789abcdef";
	*hex_u = "0123456789ABCDEF";
	r = 0;
	if (n < 16)
	{
		if (x == (char) 'X')
		{
			r = write(1, &hex_u[n], 1);
			(*count)++;
			if (r == -1)
				return (-1);
		}
		else
		{
			r = write(1, &hex[n], 1);
			(*count)++;
			if (r == -1)
				return (-1);
		}
	}
	else
	{
		r = ft_print_hex_help(n / 16, x, count);
		if (r == -1)
			return (-1);
		r = ft_print_hex_help(n % 16, x, count);
		if (r == -1)
			return (-1);
	}
	return (0);
}
