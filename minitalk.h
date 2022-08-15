/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:54:33 by lrosch            #+#    #+#             */
/*   Updated: 2021/11/09 14:55:49 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft+/ft_printf/ft_printf.h"
# include "libft+/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_data{
	int		bit;
	char	c;
}				t_data;

#endif