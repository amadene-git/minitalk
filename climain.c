/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:36:57 by admadene          #+#    #+#             */
/*   Updated: 2021/10/22 14:09:05 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long int	nb;
	int			i;
	int			sign;

	i = -1;
	nb = 0;
	sign = 1;
	if (*str == '-')
	{
		i++;
		sign = -1;
	}
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
	{
		nb += str[i] - '0';
		nb *= 10;
	}
	return ((int)((nb * sign) / 10));
}

void	send_char(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(20);
		c = c >> 1;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(2, "Error: Bad arguments!\n", 23);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "Error: Bad arguments!\n", 23);
		return (0);
	}
	while (*av[2])
		send_char(*(av[2]++), pid);
	send_char(*(av[2]), pid);
	return (0);
}
