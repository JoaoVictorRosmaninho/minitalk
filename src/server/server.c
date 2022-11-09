/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:55:44 by jv                #+#    #+#             */
/*   Updated: 2022/11/06 19:57:56 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minitalk.h"

void	get_msg(int sig, siginfo_t *info, void *context)
{
	static unsigned char	ch = 0;
	static int				i = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	ch |= (sig == SIGUSR1);
	if (i++ == 7)
	{
		i = 0;
		if (!ch)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(ch, 1);
		ch = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		ch <<= 1;
}

int	main(void)
{
	struct sigaction	get_action;

	get_action.sa_sigaction = get_msg;
	get_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &get_action, NULL);
	sigaction(SIGUSR2, &get_action, NULL);
	ft_printf("pid: %u\n", getpid());
	while (1)
	{
		usleep(300);
	}
	return (0);
}
