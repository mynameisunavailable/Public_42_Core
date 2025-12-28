/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:53:11 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/11 00:54:46 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

volatile t_server	g_message;

void	init_server(volatile t_server *new, siginfo_t *info)
{
	new->i = 0;
	if (info == NULL)
	{
		new->pid = 0;
	}
	else
	{
		new->pid = info->si_pid;
	}
}

void	addchar(int sig, siginfo_t *info, void *nothing)
{
	unsigned char		c;
	unsigned char		m;

	(void)nothing;
	if (sig == SIGUSR1)
		c = '0';
	else if (sig == SIGUSR2)
		c = '1';
	else
		c = '\0';
	if (info->si_pid != g_message.pid)
		init_server(&g_message, info);
	g_message.byte[g_message.i] = c;
	g_message.i += 1;
	if (g_message.i == 8)
	{
		g_message.byte[g_message.i] = '\0';
		m = ft_conv_bitstrtochar((char *)g_message.byte);
		write(1, &m, 1);
		g_message.i = 0;
		if (m == '\0')
			write(1, "\n", 1);
	}
	kill(g_message.pid, SIGUSR1);
}

void	init_sigaction_server(struct sigaction *new)
{
	new->sa_sigaction = &addchar;
	sigemptyset(&new->sa_mask);
	new->sa_flags = SA_SIGINFO;
	new->sa_restorer = NULL;
}

void	put_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
}

int	main(void)
{
	struct sigaction	sig1;

	init_server(&g_message, NULL);
	init_sigaction_server(&sig1);
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig1, NULL);
	put_pid();
	while (1)
	{
		pause();
	}
	return (0);
}
