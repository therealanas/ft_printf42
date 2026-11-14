
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a;
    int b;

    printf("===== CHAR =====\n");
    a = printf("Standard: %c\n", 'A');
    b = ft_printf("Custom:   %c\n", 'A');
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== STRING =====\n");
    a = printf("Standard: %s\n", "Hello, 1337!");
    b = ft_printf("Custom:   %s\n", "Hello, 1337!");
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== POINTER =====\n");
    a = printf("Standard: %p\n", (void *)&a);
    b = ft_printf("Custom:   %p\n", (void *)&a);
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== SIGNED INTEGER =====\n");
    a = printf("Standard: %d %i %d\n", 42, -42, INT_MIN);
    b = ft_printf("Custom:   %d %i %d\n", 42, -42, INT_MIN);
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== UNSIGNED =====\n");
    a = printf("Standard: %u\n", UINT_MAX);
    b = ft_printf("Custom:   %u\n", UINT_MAX);
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== HEXADECIMAL =====\n");
    a = printf("Standard: %x %X\n", 255, 255);
    b = ft_printf("Custom:   %x %X\n", 255, 255);
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== PERCENT =====\n");
    a = printf("Standard: %%\n");
    b = ft_printf("Custom:   %%\n");
    printf("Return: standard=%d | custom=%d\n\n", a, b);

    printf("===== MIXED =====\n");
    a = printf("%c | %s | %d | %u | %x | %X | %%\n",
            'Z', "1337", -123, 123, 255, 255);
    b = ft_printf("%c | %s | %d | %u | %x | %X | %%\n",
            'Z', "1337", -123, 123, 255, 255);
    printf("Return: standard=%d | custom=%d\n", a, b);

    return (0);
}

