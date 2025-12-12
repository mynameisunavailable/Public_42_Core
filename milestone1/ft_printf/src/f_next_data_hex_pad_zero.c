/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_pad_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:02:59 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_pad_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_hex_pad_zero(unsigned int u, char *tmp,
		size_t char_str_len, t_ft_print_info *info)
{
	char	*res;
	char	*tmp2;
	char	*char_str;

	if (u > 0 && ft_cins('#', info->d_flag))
	{
		if (char_str_len >= 2)
			char_str_len -= 2;
		else
			char_str_len = 0;
		char_str = create_strwc('0', char_str_len);
		tmp2 = ft_memjoin2(char_str, char_str_len, tmp, ft_strlen(tmp));
		res = ft_memappend_front("0x", 2, tmp2, ft_strlen(tmp2));
	}
	else
	{
		char_str = create_strwc('0', char_str_len);
		res = ft_memjoin2(char_str, char_str_len, tmp, ft_strlen(tmp));
	}
	free(char_str);
	return (res);
}
