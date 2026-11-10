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
    int count;
    uintptr_t p = (uintptr_t ) ptr; 

	r = 0;
    count = 0;
	r = write(1,"0x",2);
    if (r == -1)
 26     return (-1);
    count += 2;
	r = ft_print_ptr_help(p,&count);
	if (r == -1)
		return (-1);
	return (count);
}

int ft_print_ptr_help(uintptr_t n,int *count)
{
	char *hex = "0123456789abcdef";
	int r;

	r = 0;
	if (n < 16)
	{
	
		r = write(1,&hex[n],1);
        (*count)++;
		if (r == -1)
		return (-1);
	}
	else
	{
		r = ft_print_ptr_help(n/16,count);
            if (r == -1)
 43             return (-1);
		r = ft_print_ptr_help(n%16,count);
            if (r == -1)
 43             return (-1);
	}
	return (0);
}
