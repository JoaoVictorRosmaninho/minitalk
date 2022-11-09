/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:23:39 by jv                #+#    #+#             */
/*   Updated: 2022/11/06 20:25:25 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minitalk.h"

void	get_msg(int sig, siginfo_t *info, void *context)
{
	static int	deliverd = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		deliverd++;
	else
	{
		ft_printf("finishing communication, recevied messages: %d\n", deliverd);
		exit(0);
	}
}

void	hadling_connection(pid_t server_pid, char *msg, unsigned int size)
{
	unsigned int	i;
	unsigned char	mask;

	i = 0;
	while (i < size)
	{
		mask = 1 << 7;
		while (mask)
		{
			if (msg[i] & mask)
			{
				if (kill(server_pid, SIGUSR1) == -1)
					show_message("send msg error, verify the pid");
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
					show_message("send msg error, verify the pid");
			}
			usleep(300);
			mask >>= 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	get_action;

	if (argc != 3 || ft_strlen(argv[2]) < 1)
	{
		show_message("usage: ./client [pid_server] [message]");
		return (0);
	}
	ft_printf("Send Messages: %d\n", ft_strlen(argv[2]));
	get_action.sa_flags = SA_SIGINFO;
	get_action.sa_sigaction = get_msg;
	sigaction(SIGUSR1, &get_action, NULL);
	sigaction(SIGUSR2, &get_action, NULL);
	hadling_connection(ft_atoi(argv[1]), argv[2], ft_strlen(argv[2]) + 1);
	return (0);
}
