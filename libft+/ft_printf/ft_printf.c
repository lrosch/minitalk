/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:28:06 by lrosch            #+#    #+#             */
/*   Updated: 2021/09/21 14:47:04 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** overlord function that checks the parameter and instructs
** which function to use
*/

int	ft_analyze(const char *s, va_list args, int i)
{
	if (s[i + 1] == 'c')
		return (ft_printchar(args));
	if (s[i + 1] == 's')
		return (ft_printstr(args));
	if (s[i + 1] == 'i' || s[i + 1] == 'd')
		return (ft_printint(args));
	if (s[i + 1] == '%')
		return (ft_printperc());
	if (s[i + 1] == 'u')
		return (ft_printunint(args));
	if (s[i + 1] == 'x')
		return (ft_printhexlow(args));
	if (s[i + 1] == 'X')
		return (ft_printhexup(args));
	if (s[i + 1] == 'p')
		return (ft_printptr(args));
	else
		return (0);
}

/* function that gets the return value for t_printint */

int	ft_getnbrlen(int i)
{
	int	j;

	j = 0;
	if (i < 0)
		j++;
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
** function that reverses the hexadecimal string for correct
** output
*/

char	*ft_reverse(char *s)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = (ft_strlen(s) - 1);
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

/*
** main printf function that writes characters or gives
** input to different printer and helper functions
*/

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			j = j + ft_analyze(s, args, i);
			i = i + 2;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			j++;
		}
	}
	va_end(args);
	return (j);
}
