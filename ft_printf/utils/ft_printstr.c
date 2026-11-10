/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 14:44:03 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/08 16:02:37 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int 	ft_printstr(char *s)
{
	ssize_t r;
	size_t l;
	size_t count;

	count = 0;
	l = ft_strlen(s);
	r = 0;
    if (!s)
        s = "(null)";
	while (count != l)
	{	
		r = write(1,s + count,l - count);
		if (r <= 0)
			return (-1);
		count += r;
	}
	return ((int )count);
}
