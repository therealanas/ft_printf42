#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
int ft_printf(char *str, ...);
size_t ft_strlen(const char *s);
int 	ft_printchar(char s);
int ft_print_hex(int n,int x);
int ft_print_u_number(unsigned int n);
int 	ft_printstr(char *s);
int ft_print_ptr(void *ptr);
int ft_print_number(int n);
int ft_printpercent(void);
int ft_process(va_list args,char c);
int ft_print_hex_help(int n, int x, int *count);
int ft_print_ptr_help(uintptr_t ptr,int *n);
int ft_putnbr(int n, int *count);
int ft_putnbr_u(unsigned int n,int *count);
int ft_process(va_list args,char c);
#endif
