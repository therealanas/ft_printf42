/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:08:53 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/09 20:54:45 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_ptrint_u_number(unsigned int n)
{
	int count;
	int r;

	r = 0;
	count = 0;
	r = ft_putnbr_u(n,&count);\
	if (r == -1)
		return (-1);
	return (count);

}

int ft_putnbr_u(unsigned int num,int *count)
{
	char	c;
	int 	r;

	c = '0';
	r = 0;
	if (num > 9)
	{
		r = ft_putnbr_u(num / 10, count);
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
