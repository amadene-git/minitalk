/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:58:18 by admadene          #+#    #+#             */
/*   Updated: 2021/10/22 14:06:48 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

static int	i = 0;
static char	c = 0;

void	handler(int signo)
{

	if (i < 0 || i >= 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	if (signo == SIGUSR1)
		i++;
	if (signo == SIGUSR2)
	{
		c += 1 * (1 << i);
		i++;
	}
}

char	line[32000] = {0};

void	sighandler(int signo, siginfo_t *info, void *ptr)
{
	(void)ptr;	
	if (signo == SIGUSR1)
		i++;
	if (signo == SIGUSR2)
	{
		c += 1 * (1 << i);
		i++;
	}
	if (i < 0 || i >= 8)
	{
		
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	ft_putnbr((int)getpid());
	struct sigaction	sa;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	sa.sa_mask	= mask;
	sa.sa_handler = NULL;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}
