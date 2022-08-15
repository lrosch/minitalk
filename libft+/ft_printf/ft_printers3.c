/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:37:14 by lrosch            #+#    #+#             */
/*   Updated: 2021/09/22 13:05:14 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* easy number writing function for integers */

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
		}
		if (n < 10)
			ft_putchar('0' + n);
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

/* helper function for unsigned int return values */

int	ft_get_u_nbrlen(unsigned int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

/* 
** decimal to hexadecimal conversion for pointer 
** difference between ptrdectohex and normal dectohex
** is the variable type in unsigned long and unsigned int 
*/

char	*ft_ptrdectohex(unsigned long dec)
{
	unsigned long	rest;
	char			*hex;
	int				i;

	i = 0;
	hex = malloc(ft_hexlen(dec) + 1);
	if (hex == NULL)
		return (NULL);
	while (dec != 0)
	{
		rest = dec % 16;
		if (rest < 10)
		{
			hex[i] = 48 + rest;
			i++;
		}
		else
		{
			hex[i] = 55 + rest;
			i++;
		}
		dec = dec / 16;
	}
	hex[i] = '\0';
	return (ft_reverse(hex));
}
