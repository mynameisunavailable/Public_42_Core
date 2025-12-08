/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_pad.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:56:43 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_pad.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_hex_pad(unsigned int u, char *tmp, t_ft_print_info *info)
{
	size_t	char_str_len;

	if ((info->d_wide >= 0) && ((size_t)info->d_wide > ft_strlen(tmp)))
	{
		char_str_len = info->d_wide - ft_strlen(tmp);
		if (ft_cins('-', info->d_flag))
			info->o_str = f_n_n_hex_pad_dash(u, tmp, char_str_len, info);
		else if (ft_cins('0', info->d_flag) && (info->d_prec < 0))
			info->o_str = f_next_data_hex_pad_zero(u, tmp, char_str_len, info);
		else
			info->o_str = f_next_data_hex_pad_space(u, tmp, char_str_len, info);
		if ((size_t)info->d_wide >= ft_strlen(info->o_str))
			info->o_len = info->d_wide;
		else
			info->o_len = ft_strlen(info->o_str);
	}
	else
	{
		info->o_str = ft_strdup(tmp);
		if (u > 0 && ft_cins('#', info->d_flag))
			info->o_str = ft_memappend_front("0x", 2, info->o_str,
					ft_strlen(info->o_str));
		info->o_len = ft_strlen(info->o_str);
	}
	return (info->o_str);
}
