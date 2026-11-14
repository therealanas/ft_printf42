/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:08:53 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/14 13:37:21 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_print_number(int n)
{
	int count;
	int r;

	r = 0;
	count = 0;
	r = ft_putnbr(n,&count);\
	if (r == -1)
		return (-1);
	return (count);

}

int ft_putnbr(int n,int *count)
{
	char	c;
	long	num;
	int 	r;

	c = '0';
	r = 0;
	num = (long)n;
	if (num < 0)
	{
		r = write(1, "-", 1);
		if (r == -1)
			return (-1);
		*count += r;
		num *= -1;
	}
	if (num > 9)
	{
		r = ft_putnbr(num / 10, count);
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
