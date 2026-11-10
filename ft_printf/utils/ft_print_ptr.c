/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:26:40 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/10 12:38:15 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int ft_print_ptr(void *ptr)
{
	int r;

	r = 0;
	write(1,"0x",2);
	r = ft_print_hex(ptr);
	if (r == -1)
		return (-1);
	return (0);
}
