/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:52:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/11 00:53:52 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# define _GNU_SOURCE
# include <sys/types.h>
# include <signal.h>
# include "libft/include/libft.h"

struct s_server
{
	char	byte[9];
	int		i;
	int		pid;
};

typedef struct s_server	t_server;
//ft_conv_strbit.c
// char			*ft_conv_chartobitstr(unsigned char x, char *byte);
// char			*ft_conv_strtobitstr(char *msg, char *bitstr);
// unsigned char	ft_conv_bitstrtochar(char *byte);

#endif