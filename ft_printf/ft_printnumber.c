/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:00:49 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/24 15:55:18 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_number(int n)
{
	int	count;
	int	r;

	r = 0;
	count = 0;
	r = ft_putnbr(n, &count);
	if (r == -1)
		return (-1);
	return (count);
}

int	ft_putnbr(int n, int *count)
{
	long	num;
	int		r;

	r = 0;
	num = (long) n;
	if (num < 0)
	{
		r = write(1, "-", 1);
		if (r != 1)
			return (-1);
		*count += r;
		num *= -1;
	}
	r = ft_putnbr_rec(num, count);
	if (r == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_rec(long num, int *count)
{
	int		r;
	char	c;

	c = '0';
	r = 0;
	if (num > 9)
	{
		r = ft_putnbr_rec(num / 10, count);
		if (r == -1)
			return (-1);
	}
	c += num % 10;
	r = write(1, &c, 1);
	if (r == -1)
		return (-1);
	*count += r;
	return (0);
}
