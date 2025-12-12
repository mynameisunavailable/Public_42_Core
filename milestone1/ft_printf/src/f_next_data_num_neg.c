/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_num_neg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:51:07 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_num_neg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_num_neg(char *tmp, t_ft_print_info *info)
{
	size_t	char_str_len;

	if ((info->d_wide >= 0) && ((size_t)info->d_wide > ft_strlen(tmp) + 1))
	{
		char_str_len = info->d_wide - ft_strlen(tmp) - 1;
		if (ft_cins('-', info->d_flag))
		{
			info->o_str = f_next_data_num_neg_dash(tmp, char_str_len);
		}
		else if (ft_cins('0', info->d_flag) && (info->d_prec < 0))
		{
			info->o_str = f_next_data_num_neg_zero(tmp, char_str_len);
		}
		else
		{
			info->o_str = f_next_data_num_neg_space(tmp, char_str_len);
		}
		info->o_len = info->d_wide;
	}
	else
	{
		info->o_str = ft_memjoin2("-", 1, tmp, ft_strlen(tmp));
		info->o_len = ft_strlen(tmp) + 1;
	}
	return (info->o_str);
}
