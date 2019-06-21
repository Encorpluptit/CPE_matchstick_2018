/*
** EPITECH PROJECT, 2019
** C Library.
** File description:
** Good version of atoi function.
*/

#include <stdbool.h>

static bool check_char(char const c);

int my_atoi(char const *str)
{
    int nb = 0;
    bool neg = false;

    for (;*str && !check_char(*str); ++str) {
        if (*str == '-')
            neg = true;
    }
    for (; *str && check_char(*str); ++str) {
        nb = (10 * nb) + *str - '0';
    }
    neg ? nb *= -1 : 0;
    return nb;
}

static bool check_char(char const c)
{
    return (c >= '0' && c <= '9');
}
