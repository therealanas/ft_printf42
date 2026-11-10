/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 08:04:16 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/10 12:37:10 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdio.h>

int ft_print_hex(int n,int x)
{
	char *hex = "0123456789abcdef";
	char *HEX = "0123456789ABCDEF";
	int r;

	r = 0;
	if (n < 16)
	{
		if (x)
		{
			r = write(1,&HEX[n],1);
			if (r == -1)
			return (-1);
		}
		else 
		{
			r = write(1,&hex[n],1);
			if (r == -1)
			return (-1);	
		}
	} 
	else
	{
		ft_print_hex(n/16,x);
		ft_print_hex(n%16,x);
	}
	return (0);
}


