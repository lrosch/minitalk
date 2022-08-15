/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhelper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:57:11 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/03 13:34:27 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* easy write character function */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* same as ft_putnbr but for unsigned integers */

void	ft_put_u_nbr(unsigned int n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

/* helper function to lower hexadecimal array letters */

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return (ch + 32);
	}
	return (ch);
}

/*
** easy write string function, special case for "NULL"
** string -> printf writes (null) and returns value 6
*/

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
