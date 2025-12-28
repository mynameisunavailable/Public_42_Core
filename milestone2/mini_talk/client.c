/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:57:44 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/11 00:57:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static volatile t_bool	g_received = TRUE;

void	ft_received(int i)
{
	(void)i;
	g_received = TRUE;
}

void	init_sigaction_client(struct sigaction *new)
{
	new->sa_handler = &ft_received;
	sigemptyset(&new->sa_mask);
	new->sa_flags = 0;
	new->sa_restorer = NULL;
}

void	client_send_message(int pid, char *msg)
{
	char	*bitstr;
	size_t	i;

	bitstr = malloc(sizeof(char) * (ft_strlen(msg) + 1) * 8 + 1);
	ft_conv_strtobitstr(msg, bitstr);
	i = 0;
	while (bitstr[i])
	{
		g_received = FALSE;
		if (bitstr[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_received == FALSE)
			usleep(50);
		i++;
	}
	free(bitstr);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_puterr("wrong number of arguments");
		return (1);
	}
	init_sigaction_client(&sig);
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sig, NULL);
	client_send_message(pid, argv[2]);
	return (0);
}
