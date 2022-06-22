/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:37:17 by admadene          #+#    #+#             */
/*   Updated: 2021/10/22 14:02:32 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

void			ft_putnbr(int nbr);
void			sighandler(int signo, siginfo_t *info, void *ptr);
int				ft_atoi(const char *str);
void			send_char(char c, int pid);

#endif
