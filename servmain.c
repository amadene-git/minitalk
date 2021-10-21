/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:58:18 by admadene          #+#    #+#             */
/*   Updated: 2021/10/21 14:54:38 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);
void sighandler(int signo);
sighandler_t signal(int signum, sighandler_t handler);


void sighandler(int signo)
{
	static int 	i = 0;
	static char	c = 0;

	if (i < 0 || i >= 8)
	{
		write(1, &c ,1);
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

int main()
{
	printf("%d\n", getpid());

	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while(1);
	return (0);
}
