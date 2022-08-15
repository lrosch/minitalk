/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:55:41 by lrosch            #+#    #+#             */
/*   Updated: 2021/09/13 14:30:43 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** function that determines the needed length for
** the hexadecimal array
*/

int	ft_hexlen(unsigned long dec)
{
	int	i;

	i = 0;
	while (dec != 0)
	{
		dec = dec / 16;
		i++;
	}
	return (i);
}

/*
** same function as ft_ptrdectohex without unsigned long
** prints in upper hexadecimal
*/

char	*ft_dectohex(unsigned int dec)
{
	unsigned int	rest;
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

/* function that prints upper case hexadecimal */

int	ft_printhexup(va_list args)
{
	unsigned int	dec;
	char			*hex;
	int				i;

	dec = va_arg(args, unsigned int);
	if (dec == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = ft_dectohex(dec);
	ft_putstr(hex);
	i = (ft_strlen(hex));
	free (hex);
	return (i);
}

/* function that prints lower case hexadecimal */

int	ft_printhexlow(va_list args)
{
	unsigned int	dec;
	char			*hex;
	int				i;
	int				j;

	j = 0;
	dec = va_arg(args, unsigned int);
	if (dec == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = ft_dectohex(dec);
	while (hex[j] != '\0')
	{
		hex[j] = ft_tolower(hex[j]);
		j++;
	}
	ft_putstr(hex);
	i = (ft_strlen(hex));
	free (hex);
	return (i);
}

/* function that prints pointers in lower case hexadecimal */

int	ft_printptr(va_list args)
{
	unsigned long	addr;
	void			*ptr ;
	char			*hex;
	int				j;
	int				i;

	j = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	addr = (unsigned long) ptr;
	write(1, "0x", 2);
	hex = ft_ptrdectohex(addr);
	while (hex[j] != '\0')
	{
		hex[j] = ft_tolower(hex[j]);
		j++;
	}
	ft_putstr(hex);
	i = (ft_strlen(hex) + 2);
	free (hex);
	return (i);
}
