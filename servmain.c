/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:58:18 by admadene          #+#    #+#             */
/*   Updated: 2021/10/21 15:53:14 by admadene         ###   ########.fr       */
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

void	sighandler(int signo)
{
	static int	i = 0;
	static char	c = 0;

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

int	main(void)
{
	ft_putnbr((int)getpid());
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		continue ;
	return (0);
}
