#include "ft_printf.h"

int ft_printf(char *str, ...)
{
va_list args;

va_start(args,str);
    while (*str)
    {
        if (*str == '%' && *(str+1))
        {
            ft_process(va*(str+1));
        }
    }

}
