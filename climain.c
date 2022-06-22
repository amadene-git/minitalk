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

static char	g_recept = 0;

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
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Client error\n", 13);
				exit(EXIT_FAILURE);
			}
		}
		else if (kill(pid, SIGUSR1) == -1)
		{
			write(2, "Client error\n", 13);
			exit(EXIT_FAILURE);
		}
		c = c >> 1;
		while (!g_recept)
			;
		g_recept = 0;
	}
}

void	sighandler(int signo, siginfo_t *info, void *ptr)
{
	(void)signo;
	(void)info;
	(void)ptr;
	g_recept = 1;
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;
	sigset_t			mask;

	if (ac != 3 || ft_atoi(av[1]) <= 0)
	{
		write(2, "Error: Bad arguments!\n", 23);
		return (0);
	}
	pid = ft_atoi(av[1]);
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	sa.sa_mask = mask;
	sa.sa_handler = NULL;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (*av[2])
		send_char(*(av[2]++), pid);
	send_char(*(av[2]), pid);
	return (0);
}
