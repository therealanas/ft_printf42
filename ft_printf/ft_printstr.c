/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:03:02 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/24 15:47:46 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstr(char *s)
{
	ssize_t	r;
	size_t	count;

	count = 0;
	r = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		r = write(1, s++, 1);
		if (r != 1)
			return (-1);
		count += r;
	}
	return ((int) count);
}
