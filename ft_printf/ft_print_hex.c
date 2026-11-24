/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:58:43 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/24 14:56:42 by ahoumdi          ###   ########.fr       */
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

	hex = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	r = 0;
	if (n < 16)
	{
		if (x == (char) 'X')
			return (ft_print_hex_help_helper(hex_u, count, n));
		else
			return (ft_print_hex_help_helper(hex, count, n));
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

int	ft_print_hex_help_helper(char *hex, int *count, int n)
{
	int	r;

	r = 0;
	r = write(1, &hex[n], 1);
	(*count)++;
	if (r != 1)
		return (-1);
	return (r);
}
