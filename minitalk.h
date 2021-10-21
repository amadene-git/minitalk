/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:37:17 by admadene          #+#    #+#             */
/*   Updated: 2021/10/21 15:40:05 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

typedef void (*sighandler_t)(int);

sighandler_t	signal(int signum, sighandler_t handler);
void			ft_putnbr(int nbr);
void			sighandler(int signo);
int				ft_atoi(const char *str);
void			send_char(char c, int pid);
#endif
