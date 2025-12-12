/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_prec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:40:00 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_prec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_hex_prec(unsigned int u, t_ft_print_info *info)
{
	char	*tmp;

	if (info->d_prec >= 0)
	{
		if ((info->d_prec == 0) && (u == 0))
			tmp = ft_strdup("");
		else
			tmp = ft_uitoh(u);
		if (ft_strlen(tmp) < (size_t)info->d_prec)
		{
			tmp = f_next_data_hex_prec_padc(tmp, info);
			info->o_len = info->d_prec;
		}
	}
	else
		tmp = ft_uitoh(u);
	return (tmp);
}
