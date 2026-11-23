/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:03:02 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/23 16:03:08 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstr(char *s)
{
	ssize_t	r;
	size_t	l;
	size_t	count;

	count = 0;
	r = 0;
	if (!s)
		s = "(null)";
	l = ft_strlen(s);
	while (count != l)
	{
		r = write(1, s + count, l - count);
		if (r <= 0)
			return (-1);
		count += r;
	}
	return ((int) count);
}
