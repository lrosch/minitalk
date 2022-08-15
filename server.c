/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:22 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/11 10:52:56 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_initialize(void)
{
	pid_t	pid;

	g_data.bit = 8;
	g_data.c = 0;
	pid = getpid();
	ft_printf("Process-ID of the Server: %i\n", pid);
}

void	ft_handler0(int signal)
{
	signal = 0;
	g_data.bit--;
	g_data.c += (0 << g_data.bit);
	if (g_data.bit == 0)
	{
		ft_putchar_fd(g_data.c, 1);
		g_data.bit = 8;
		g_data.c = 0;
	}
}

void	ft_handler1(int signal)
{
	signal = 0;
	g_data.bit--;
	g_data.c += (1 << g_data.bit);
	if (g_data.bit == 0)
	{
		ft_putchar_fd(g_data.c, 1);
		g_data.bit = 8;
		g_data.c = 0;
	}
}

int	main(void)
{
	ft_initialize();
	while (1)
	{
		signal(SIGUSR1, ft_handler0);
		signal(SIGUSR2, ft_handler1);
	}
	return (0);
}
