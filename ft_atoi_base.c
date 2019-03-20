/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:29:34 by fshade            #+#    #+#             */
/*   Updated: 2019/03/20 15:24:04 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int        ft_isspace(int n)
{
    return (n == ' ' || n == '\t' || n == '\n' || n == '\v' || n == '\f'
            || n == '\r');
}

static int            ft_is_allowed_symbol(char c, int base)
{
    const char        *symbols = "0123456789ABCDEF";
    int                i;

    i = 0;
    while (i < base)
    {
        if (symbols[i] == ft_toupper(c))
            return (i);
        i++;
    }
    return (-1);
}

/*
** Проверяет содержит ли эта строка префикс своей числовой системы
*/

static int            ft_has_prefix(const char *str, int base)
{
    size_t            i;

    i = 0;
    if (base == 2 || base == 8 || base == 16)
    {
        if (str[i++] != '0')
            return (0);
        if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
            return (1);
        if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
            return (1);
        if (base == 8)
            return (1);
    }
    return (0);
}

/*
** Преобразовывает строку в число в соответствии с выбранной системой счисления
*/

int                    ft_atoi_base(const char *str, int base)
{
    size_t            i;
    int              negative;
    unsigned long    result;

    i = 0;
    result = 0;
    negative = 1;
    while (ft_isspace(str[i]))
        i++;
    if (base != 10 && ft_has_prefix(&str[i], base) == 0)
        return (0);
    if (base == 2 || base == 16)
        i = i + 2;
    else if (base == 8)
        i++;
    else if (base == 10 && (str[i] == '-' || str[i] == '+'))
        negative = (str[i++] == '-') ? -1 : 1;
    while (ft_is_allowed_symbol(str[i], base) >= 0)
        result = result * base + ft_is_allowed_symbol(str[i++], base);
    return ((int)(result * negative));
}