/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:54:38 by lrosch            #+#    #+#             */
/*   Updated: 2021/09/07 13:41:46 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
** functions to print strings, percents
** characters, integers and unsigned integers
*/

int	ft_printstr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr(str);
	if (str != NULL)
		return (ft_strlen(str));
	else
		return (6);
}

int	ft_printperc(void)
{
	write (1, "%", sizeof(char));
	return (sizeof(char));
}

int	ft_printchar(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write (1, &c, 1);
	return (sizeof(char));
}

int	ft_printint(va_list args)
{
	int	i;

	i = va_arg(args, int);
	ft_putnbr(i);
	return (ft_getnbrlen(i));
}

int	ft_printunint(va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if (i >= 0)
	{
		ft_put_u_nbr(i);
		return (ft_get_u_nbrlen(i));
	}
	return (0);
}
