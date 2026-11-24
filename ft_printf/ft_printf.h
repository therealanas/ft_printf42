/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:00:23 by ahoumdi           #+#    #+#             */
/*   Updated: 2026/11/24 14:39:42 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_printchar(char s);
int		ft_print_hex(unsigned int n, int x);
int		ft_print_u_number(unsigned int n);
int		ft_printstr(char *s);
int		ft_print_ptr(void *ptr);
int		ft_print_number(int n);
int		ft_printpercent(void);
ssize_t	ft_process(va_list *args, char c);
int		ft_print_hex_help(unsigned int n, int x, int *count);
int		ft_print_ptr_help(uintptr_t ptr, int *n);
int		ft_putnbr(int n, int *count);
int		ft_putnbr_u(unsigned int n, int *count);
int		ft_print_hex_help_helper(char *hex, int *count, int n);
int		ft_putnbr_rec(long num, int *count);
#endif
