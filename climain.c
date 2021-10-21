/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:36:57 by admadene          #+#    #+#             */
/*   Updated: 2021/10/21 14:54:36 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	send_char(char c, int pid)
{
	int	i = 0;

	while (i < 8)
	{
		if (c % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(20);
		c = c >> 1;
		i++;
	}
}

int main(int ac, char **av)
{
	int pid = atoi(av[1]);
	
	if (ac != 3)
	{
		printf("Bad arg!\n");
		return (0);
	}
	while (*av[2])
		send_char(*(av[2]++), pid);
	return (0);
}
  

