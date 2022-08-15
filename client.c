/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:42:45 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/09 10:36:01 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_send(char c, pid_t server_id)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(server_id, SIGUSR2);
		else
			kill(server_id, SIGUSR1);
		usleep(50);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_id;
	char	*string;
	int		i;

	if (argc != 3 || !check_isdigit(argv[1]))
	{
		ft_printf("invalid input\n");
		return (0);
	}
	i = 0;
	server_id = ft_atoi(argv[1]);
	string = argv[2];
	while (string[i] != '\0')
	{
		ft_send(string[i], server_id);
		i++;
	}
	ft_printf("Data sent\n");
	return (0);
}
